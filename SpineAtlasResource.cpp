//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineAtlasResource.h"
#include <spine/Atlas.h>

class RaiixSpineTextureLoader : public spine::TextureLoader {
private:
    SpineAtlasResource &res;
public:

    RaiixSpineTextureLoader(SpineAtlasResource &r):res(r){}

    virtual void load(spine::AtlasPage &page, const spine::String &path){
		//Ref<Texture> *p_tex = memnew(Ref<Texture>(tex));
		auto p_spine_renderer_object = memnew(SpineRendererObject);

		// Load texture (e.g. tex.png)
		Ref<Texture> tex = ResourceLoader::load(String(path.buffer()));
		res.texes.append(tex);
		p_spine_renderer_object->tex = tex;

		// Load normal texture (e.g. tex_n.png)
		String temppath = String(path.buffer());
		String newpath = temppath.substr(0, temppath.length() - 4) + "_n" + temppath.right(temppath.length() - 4);
		if (ResourceLoader::exists(newpath)){
			Ref<Texture> normal_tex = ResourceLoader::load(newpath);
			res.normal_texes.append(normal_tex);
			p_spine_renderer_object->normal_tex = normal_tex;

			// print_line(String("From atlas resource load: ") + String(" ro ") + String(Variant((long long) p_spine_renderer_object)));
			// print_line(String("From atlas resource load: ") + String(Variant(p_spine_renderer_object->tex)) + String(", ") + String(Variant(p_spine_renderer_object->normal_tex)));
		}

		page.setRendererObject((void*)p_spine_renderer_object);		

		page.width = tex->get_width();
		page.height = tex->get_height();
    }

    virtual void unload(void *p){
		// print_line("I'm out.");
		auto p_spine_renderer_object = (SpineRendererObject*) p;
        Ref<Texture> &tex = p_spine_renderer_object->tex;
		Ref<Texture> &normal_tex = p_spine_renderer_object->normal_tex;

		res.texes.remove(res.texes.find(tex));
		int normal_position = res.normal_texes.find(normal_tex);
		if (normal_position != -1)
		res.normal_texes.remove(normal_position);

        tex.unref();
		normal_tex.unref();

		memdelete(p_spine_renderer_object);
    }
};

Error SpineAtlasResource::load_file(const String &p_path) {
	atlas = new spine::Atlas(spine::String(p_path.utf8()), new RaiixSpineTextureLoader(*this));
    return OK;
}

SpineAtlasResource::SpineAtlasResource():atlas(NULL) {

}
SpineAtlasResource::~SpineAtlasResource() {
    if(atlas){
        delete atlas;
        atlas = NULL;
    }
}

void SpineAtlasResource::_bind_methods(){
	ClassDB::bind_method(D_METHOD("get_textures"), &SpineAtlasResource::get_textures);
	ClassDB::bind_method(D_METHOD("set_textures", "array"), &SpineAtlasResource::set_textures);
	ClassDB::bind_method(D_METHOD("get_normal_textures"), &SpineAtlasResource::get_normal_textures);
	ClassDB::bind_method(D_METHOD("set_normal_textures", "array"), &SpineAtlasResource::set_normal_textures);

	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "textures"), "set_textures", "get_textures");
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "normal_textures"), "set_normal_textures", "get_normal_textures");
}

void SpineAtlasResource::set_textures(const Array &ts) {
	static bool has_start = false;
	texes = ts;
	if(has_start) return;
	has_start = true;
	reload_from_file();
	has_start = false;
}
Array SpineAtlasResource::get_textures() {
	return texes;
}

void SpineAtlasResource::set_normal_textures(const Array &ts) {
	static bool has_start = false;
	normal_texes = ts;
	if(has_start) return;
	has_start = true;
	reload_from_file();
	has_start = false;
}
Array SpineAtlasResource::get_normal_textures() {
	return normal_texes;
}
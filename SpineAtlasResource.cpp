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

    String fixPathIssue(const String &path){
        if(path.size() > 5 && path[4] == '/' && path[5] == '/') return path;
        const String prefix = "res:/";
        auto i = path.find(prefix);
//        print_line(String("Found i at ") + String(Variant(i)));
        auto sub_str_pos = i+prefix.size()-1;
        if(sub_str_pos < 0) return path;
        auto res = path.substr(sub_str_pos);
//        print_line(String("rest of it: ") + res);
        if(res.size() > 0)
        {
            if(res[0] != '/')
            {
                return prefix + "/" + res;
            } else
            {
                return  prefix + res;
            }
        }
        return path;
    }

    virtual void load(spine::AtlasPage &page, const spine::String &path){
		//Ref<Texture> *p_tex = memnew(Ref<Texture>(tex));
		auto p_spine_renderer_object = memnew(SpineRendererObject);

//		print_line(String("Spine is loading texture: ") + String(path.buffer()));
        auto fixed_path = fixPathIssue(String(path.buffer()));
//        print_line("Fixed path: " + fixed_path);

		// Load texture (e.g. tex.png)
		Ref<Texture> tex = ResourceLoader::load(fixed_path);
		res.texes.append(tex);
		p_spine_renderer_object->tex = tex;

		// Load normal texture (e.g. tex_n.png)
		String temppath = fixed_path;
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
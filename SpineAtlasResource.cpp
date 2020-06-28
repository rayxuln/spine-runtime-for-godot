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
//        print_line(String("Atlas tex path: ") + String(path.buffer()));

//        Ref<Image> img;
//		img.instance();
//		print_line(Variant((int)ImageLoader::load_image(String(path.buffer()), img)));
		Ref<Texture> tex = ResourceLoader::load(String(path.buffer()));
//		print_line(Variant((int)r_err));

		Ref<Texture> *p_tex = memnew(Ref<Texture>(tex));
//        Ref<ImageTexture> &tex = *p_tex;
//        tex->create_from_image(img);
		res.texes.append(tex);
		Array pointer;
		pointer.append(p_tex);

		String temppath = String(path.buffer());
		String newpath = temppath.substr(0, temppath.length() - 4) + "_n" + temppath.right(temppath.length() - 4);
		if (ResourceLoader::exists(newpath)){
			Ref<Texture> normal_tex = ResourceLoader::load(newpath);
			Ref<Texture> *p_normal_tex = memnew(Ref<Texture>(normal_tex));
//        Ref<ImageTexture> &tex = *p_tex;
//        tex->create_from_image(img);
			res.normal_texes.append(normal_tex);
			pointer.append(normal_tex);

		}
		res.pointers.append(pointer);
		Array *p_pointer = memnew(Array(pointer));
		page.setRendererObject((void*)p_pointer);		

		page.width = tex->get_width();
		page.height = tex->get_height();
    }

    virtual void unload(void *vp_array){
		Array &array = *((Array *)vp_array);
		for (int i = 0; i < array.size(); i++){
			Array temparray = array.get(i);
			for (int j = 0; j < temparray.size(); j++){
				Variant vp_tex= array.get(i).get(j); 
				Ref<ImageTexture> tex = (Ref<ImageTexture>)vp_tex;
				tex.unref();
				memfree(*tex);
			}
		}
		memfree((Array*)vp_array);
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
# Spine Runtime for Godot Engine
runtime version 3.8.95



作者: Raiix

本项目为Godot引擎的模组，用于加载Spine的骨骼动画并渲染播放。

适用于Spine3.8.x版本。

# 说明
添加了SpineSprite节点，用于加载Spine的骨骼动画(需提供.atlas文件，图片文件和.json文件，atlas资源会自动加载图片)，并提供方法用于控制动画的播放，动画的混合等。同时提供相应的信号，用于处理骨骼动画发出的事件。

# 编译说明
将本仓库克隆到`godot/modules/`文件夹下，并将`spine-runtime-for-godot`文件夹重命名为`spine_runtime`，然后编译引擎即可。

# 许可证
按照Spine官方声明的，使用spine-runtime需在 [Spine Runtime许可证](https://github.com/EsotericSoftware/spine-runtimes/blob/3.8/LICENSE "Spine Runtime License") 下进行。
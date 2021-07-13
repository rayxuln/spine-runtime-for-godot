# 适用于Godot引擎的Spine运行库模组
本项目为Godot引擎的模组，用于加载Spine的骨骼动画并渲染播放。

适用于[Spine4.0.x](https://github.com/EsotericSoftware/spine-runtimes/commit/679b1d9c6c87fe46d927191a4581066524935f22)版本。

适用于Godot3.x版本。


# 说明
添加了SpineSprite节点，用于加载Spine的骨骼动画(需提供.atlas文件，图片文件和.json文件，atlas资源会自动加载图片)，并提供方法用于控制动画的播放，动画的混合等。同时提供相应的信号，用于处理骨骼动画发出的事件。

# 编译
将本仓库克隆到`godot/modules/`文件夹下，并将`spine-runtime-for-godot`文件夹重命名为`spine_runtime`，然后编译引擎即可。

# 许可证
按照Spine官方声明的，使用spine-runtime需在 [Spine Runtime License Agreement](http://zh.esotericsoftware.com/spine-runtimes-license) 下进行。

除了`spine-cpp`文件夹下的其他代码，均为MIT协议。
# Spine Runtime for Godot Engine

[简体中文](readme_zh.md)

spine runtime version [4.0.x](https://github.com/EsotericSoftware/spine-runtimes/commit/679b1d9c6c87fe46d927191a4581066524935f22)

godot engine version 3.x

This project is a module of Godot engine, used to load Spine's skeleton animation and render and play.

Applicable to Spine 4.0.x version.

# Description
Added SpineSprite node for loading Spine's skeletal animation (need to provide .atlas file, picture file and .json file, atlas resource will automatically load picture), and provide methods for controlling animation playback, animation mixing, etc. At the same time, it provides corresponding signals for processing the events emitted by the skeleton animation.

# Gotchas
Compiling godot for debug (-Od flag) will severely impact performance
Compile with -O2 flag for godot engine and run linker can double fps

# Compilation instructions
Clone this repository to the `godot/modules/` folder as `spine_runtime`, then compile the engine.

# License
According to Spine's official statement, the use of spine-runtime-cpp is required under [Spine Runtime License Agreement](http://zh.esotericsoftware.com/spine-runtimes-license).

Other code except those under `spine-cpp` folder is under MIT license.
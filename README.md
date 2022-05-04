[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/andreasdr/tdme2/blob/master/LICENSE)
[![NIX Build Status](https://github.com/andreasdr/tdme2/actions/workflows/nix.yml/badge.svg)](https://github.com/andreasdr/tdme2/actions)
[![MacOSX Build Status](https://github.com/andreasdr/tdme2/actions/workflows/macosx.yml/badge.svg)](https://github.com/andreasdr/tdme2/actions)
[![Windows/MINGW Build Status](https://github.com/andreasdr/tdme2/actions/workflows/windows-mingw.yml/badge.svg)](https://github.com/andreasdr/tdme2/actions)
[![Windows/MSC Build Status](https://github.com/andreasdr/tdme2/actions/workflows/windows-msc.yml/badge.svg)](https://github.com/andreasdr/tdme2/actions)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/15611/badge.svg)](https://scan.coverity.com/projects/andreasdr-tdme2)  
  
![LOGO](https://raw.githubusercontent.com/andreasdr/tdme2/master/resources/github/tdme2-logo.png)

# 1. What is TDME2?
- ThreeDeeMiniEngine2 is a lightweight, multiplatform 3D engine including tools
  - Read about the [philosophy](./README-Philosophy.md) if interested
  - See [screenshots](./README-Screenshots.md), if you want to quickly know where we are and where we will go :) 
- TDME2 is open source
  - please check the [license](https://github.com/andreasdr/tdme2/blob/master/LICENSE)
  - you find the source code at [https://github.com/andreasdr/tdme2](https://github.com/andreasdr/tdme2) 
  - you find binary alpha builds at [http://drewke.net/tdme2](http://drewke.net/tdme2)
  - here you find developer documentation including collaboration graphs and [private API](http://drewke.net/tdme2-documentation/alpha/private) as well as [public API](http://drewke.net/tdme2-documentation/alpha/public) for current alpha build
    - RapidJSON is included, but not yet integrated into documentation, please see [http://rapidjson.org/](http://rapidjson.org/)
    - For TDME2 GUI XML documentation, see [README-GUI-XML.md](./README-GUI-XML.md)

# 2. Features
- Application
    - initialization
      - loads and initializes renderer backend plugin
      - creates main window and OpenGL/Vulkan context using GLFW3
    - handles HID
    - supports
      - setting window position and dimension
      - setting full screen or windowed, borderless windowed mode
      - setting application icon
      - setting mouse position and mouse cursor
      - executing other applications or background applications
      - swapping double buffered buffers (to screen) manually if required
      - checking if application is active (port-mingw, port-msc only for now)
      - setting and getting data from clipboard
    - provides
      - a crash handler for port-msc and port-mingw which also saves backtrace to crash.log
      - application life cycle
- Math
    - Math class with common math functions
    - Vector2, Vector3, Vector4, Matrix3x3, Matrix4x4 and Quaternion class
        - those have a ordinary API + operators, the latter is still a bit WIP
- 3D engine
    - model reader
        - DAE
            - node names/ids must not have whitespace characters
            - requires baked matrices
            - requires triangulated meshes for now
        - FBX via FBX SDK
        - GLTF via tinygltf
        - TDME Model file format
            - this is a much more efficient model file format for TDME
            - can also be written
    - objects/entity types
        - 3d model based objects with
            - animations
                - supports model object base animation and animation overlays
                - supports animation blending
            - skinning via
                - CPU on GL2, GL3+/CORE, GLES2
                - GPU via compute shaders with GL4.3+/CORE, Vulkan, GL3+/CORE via OpenCL for MacOSX
                - which also supports several instances of the same object to reduce compute and render calls
            - both animations and skinning have some sort of configurable LOD functionality
            - texture transformations/animations
                - via texture matrices
        - objects with support for LOD
        - imposter objects with support for LOD
        - render group objects for foliage and such including LOD support
        - particle systems which
          - are object based
          - or point based, including sprite sheet animation support
          - or for fog purposes
          - and support
            - basic/point emitter
            - sphere emitter
            - bounding box emitter
            - circle on plane emitter
            - ...
          - there is also support for particle system groups
        - lines based objects
        - entity hierarchy objects
        - environment mapping objects
          - which can be used as reflection sources of other objects
        - decal objects
    - object/entity transformations
        - scaling
        - rotations
        - translation
    - color effects on objects/entities
        - color addition
        - color multiplication
    - lighting
    	- supports specular lighting
        	- supports phong lighting
        	- supports phong shading on GL2, GL3+/CORE, Vulkan
        	- supports gouraud shading on GLES2
        	- supports diffuse mapping on GLES2, GL2, GL3+/CORE, Vulkan
        	- supports specular shininess mapping on GL3+/CORE, Vulkan
        	- supports normal mapping on GL3+/CORE, Vulkan
        	- supports reflection mapping from cube maps on GLES2, GL2, GL3+/CORE, Vulkan
        - supports PBR lighting with IBL
        - supports deferred shading and forward shading on GL3+/CORE, Vulkan
    - custum shaders that currently include
      - specular lighting
      - specular lighting + foliage
      - specular lighting + tree
      - specular lighting + terrain
      - specular lighting + water
      - sky(no lighting + fragment depth at maximum)
      - PBR lighting
      - PBR lighting + foliage
      - PBR lighting + tree
    - shadow mapping
    - early z rejection
    - post processing
      - depth blur
      - desaturation
      - light scattering
      - SSAO
      - vignette
    - object picking
    - camera control
      - set up look from, look at, up vector can be computed
      - frustum culling via oct tree
    - supports offscreen instances
        - rendering can be captured as screenshot
        - rendering can be used (in other engine instances) as diffuse texture
    - supports down/up scaled rendering of main engine
    - screenshot ability
    - multiple renderer backends, which are loaded at runtime
      - GLES2, GL2, GL3+/CORE and Vulkan
- Physics via ReactPhysics3D 0.7.0
    - have sphere, capsule, obb, convex mesh, concave terrain mesh, height map bounding volumes
    - have multiple bounding volumes per body
    - have static, dynamic rigid bodies and collision bodies
    - uses discrete collision detection
    - rigid body simulator
    - ray tracing
    - for RP3D internals and additional features see ReactPhysics3D website
- Path finding/flow maps
    - uses A*
    - is paired with physics world to determine if a "cell" is walkable
    - optional custom walkable test
    - path finding utility supports generating flow maps
- 3D audio
    - decoder
      - ogg vorbis decoder
    - audio entities
      - streams
      - sounds
- Video
    - decoder
      - mpeg1 decoder
- GUI system
    - borrows some ideas from Nifty-GUI regarding XML and layouting
    - borrows some ideas from AngularJS like
        - all nodes are in the GUI node tree and can be made visible or unvisible depending on conditions
    - adds some improvements like
        - support auto keyword with nodes width and height attributes
        - layouting on demand in combination with conditions
    - supported primitive nodes from which compounds are built of
        - element
        - gradient
        - image(plus framebuffer and texture image nodes) 
        - input
        - layer
        - layout
        - panel
        - scrollbars
        - space
        - table
        - text + multiline/styled text
    - supports custom templates and compound elements defined by templates and its controllers
        - compound elements
            - button
            - checkbox
            - dropdown
            - image button
            - input
            - knob
            - menu
            - progress bar
            - radio button
            - scrollarea
            - selectbox including tree view
            - selector horizontal
            - slider horizontal
            - slider vertical
            - tabs
        - supports custom templates in general
        - supports overriding used template of a compound element while using its controller
        - so TDME2 GUI is fully customizable in terms of appearance by modifying or adding XML template definitions
    - includes a simple script language
        - to react on events with like on-mouse-click, ... and on-change for elements
        - to manipulate conditions of elements, values of element controller and node properties
    - supports position and color based effects in combination with conditions that can also be defined via XML
- MiniScript
	- very small implementation of a scripting language without byte code, VM or what ever
	- runs on every CPU, OS, ... due to its simplicity, so its highly portable just like TDME2 is
	- can be easily extended by writing state machine machine states and script methods in C++
	- only works with the following data type primitives: boolean, integer, float, string, vector3 and transformations
	- when calling script methods/returning from methods it does not use references or pointers but only value by copy
	- supports operators by operator to method mapping by a preprocessor run
	- supports loops and conditions
	- sort of event based
	- how to use:
	  - each script is attached to a game entity so it for now does not need something like OOP
	  - communication between script instances is possible by sending signals with arguments
	  - complex logic should still be implemented by a game developer in C++ by extending MiniScript
	  - game designers can use MiniScript + those methods to implement high level game logic
	- MiniScript methods/states know about them self, so a whole documentation for MiniScript usage can be generated later
	- can be transpiled to C++
- Networking module, which consists of
    - UDP server
        - n:m threading model with non blocked IO via kernel event mechanismns(epoll, kqueue or select)
        - supports safe messages with acknowledgment and automatic resending
        - supports fast messages
        - can be used in a heavy multithreaded environment (the networking module is thread safe)
        - IPV6 ready
    - UDP client
        - has single thread with a simple threadsafe API
        - supports all features required by UDP server
        - IPV6 ready
    - Simple HTTP client
        - uses a blocking TCP socket, thus it has a simple blocking API
        - Ready for REST providing all methods, setting content type and body
        - be able to set GET and POST parameters via unordered map 
        - supports basic authentification
        - IPV6 ready
    - HTTP download client
        - supports basic authentification
        - uses a separate thread to download to file
        - IPV6 ready
- Operating system abstraction layer
    - file system
        - standard file system
        - zlib based compressed archive file system and a tool to generate it from ./resources and ./shader folder
    - multi threading
        - atomic operations
        - barrier
        - condition
        - consumer/producer queue
        - mutex
        - read write lock
        - spin lock
        - thread

# 3. Tools
- Editor
    - This is our content editor, please see [README-Editor.md](./README-Editor.md)
- Installer
    - TDME2 itself and TDME2 applications can be installed with TDME2 installer, which supports
        - offline installations
        - installation using HTTP download from a repository which is easy to set up
        - updating/repairing/uninstalling
    - TDME2 tools contains the installer creation application, whereas
        - installer definitions are set up using property files
        - create-installer is able to group files into components
- Other tools
    - archive tool to generate a single compressed file file system from ./resources and ./shader folders
    - converttotm tool to generate TDME2 model files
    - createinstaller tool to generate installer application and archives
    - generatelicenses tool to generate complete engine or project licenses from ./ext folders
    - importtmodel tool to generate TDME2 tmodel prototype files using model and bounding volumes models
    - makefilegenerator tool to generate Makefiles for TDME2 based projects
    - miniscripttranspiler tool to transpile MiniScript code to C++ code
    - optimizemodel tool to generate texture atlases and bake down model mesh nodes into a few one to reduce GL/VK (render/compute) calls
    - sortincludes tool to sort "include" and "using" source code statements
    - others ...

# 4. What does it (maybe still) lack
- physics
  - some more RP3D integration
- example games
- documentation

# 5. What is WIP or planned
- PBR: generate IBL cube maps from scene
- Shader parameters, the system is implemented and working, now lets connect tools and shaders
- Reflections via environment mapping(reflection intensity maps feature is missing for specular materials)
- Optimizing models with specular lighting regarding render calls by reducing nodes and materials to a minumum
- GUI effects via XML definitions
- Port WarStorys "Game Foundation" to TDME2, which organizes game logics, enables communcation between them and enables to do network IO and such
- MiniScript: more engine bindings
- Add nmake support to makefile generator for TDME2 based projects
- Editor: complete Undo/Redo and Copy/Cut/Paste/Delete
- Editor: Code editing with code completion, also visual code and shader editing is planned!
- Vulkan: Performance improvements
- Some UI elements need some focus/disabled fixes
- A release plan
- A demonstration video

# 6. Technology
- designed for simple multi threading, but
    - 3D rendering engine uses multiple threads if using Vulkan renderer, or one thread only if using a GL renderer
    - UDP client has its own thread
    - UDP server can have multiple IO threads, multiple worker threads and always has its own server thread
    - HTTP download client has its own thread
    - physics or game mechanics can also run in a separate thread(s)
- uses 3rd party libraries
    - needs to be installed 
        - OpenGL
        - OpenAL
        - glew
        - pthreads
        - GLFW3
        - Vulkan(optional)
    - included in TDME2 repository
        - FBXSDK
        - libpng
        - pl_mpeg
        - ReactPhysics3D
        - RapidJSON
        - sha256
        - tinygltf
        - tinyxml
        - V-HACD
        - Vorbis/OGG
        - Vulkan
          - glslang
          - OGLCompilersDLL
          - simple_vulkan_synchronization
          - spirv
          - VulkanMemoryAllocator
        - zlib
- targeted platforms and its current state
    - Windows/MINGW(port completed)
    - Windows/MSC(port completed)
    - Linux(port completed)
    - MacOSX(port completed)
    - FreeBSD(port completed)
    - NetBSD(port completed)
    - OpenBSD(port completed)
    - Haiku(port completed)
    - Android(port pending)
    - iOS(port pending)

# 7. Other information
## 7.1. Links
- TDME2 Philosophy, see [README-Philosophy.md](./README-Philosophy.md)
- TDME2 Engine, see [README.md](./README.md)
- TDME2 Editor, see [README-Editor.md](./README-Editor.md)
- TDME2 How to build, see [README-BuildingHowTo.md](./README-BuildingHowTo.md)
- TDME2 Screenshots, see [README-Screenshots.md](./README-Screenshots.md)

## 7.2. External references
- "ReactPhysics3D" physics library, [http://www.reactphysics3d.com](http://www.reactphysics3d.com) 
- the world wide web! thank you for sharing, see [README-WebReferences.md](./README-WebReferences.md)

## 7.3. Other credits
- Dominik Hepp
- Mathias Lenz
- Kolja Gumpert
- Mathias Wenzel
- Sergiu Crăiţoiu
- Chantal Zabel
- others

## 7.4. Special thanks go to
- Kristin Meissner
- Dominik Hepp

# 8. Collaboration
- Interested in collaboration? Then drop me a line via mail or use the issues section on [tdme2@github](https://github.com/andreasdr/tdme2/issues) or on [tdme2@codecks](https://open.codecks.io/tdme2)
    - You can help with testing and reporting bugs 
    - I have easy to hard task regarding engine/tools development
    - I have tasks regarding documentation
    - I even might have system administrator tasks

# 9. Donation 
- I have to pay my bills and beer, so if you have any use for this open source project, like educational, productive or fun, ..., consider a donation here https://www.paypal.me/andreasdrewke or here https://github.com/sponsors/andreasdr

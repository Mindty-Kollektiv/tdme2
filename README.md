[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/andreasdr/tdme2/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/andreasdr/tdme2.svg?branch=master)](https://travis-ci.org/andreasdr/tdme2)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/15611/badge.svg)](https://scan.coverity.com/projects/andreasdr-tdme2)
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/andreasdrewke)
![LOGO](https://raw.githubusercontent.com/andreasdr/tdme2/master/resources/logos/github-logo.png)

- What is TDME2?
    - ThreeDeeMiniEngine2 is a lightweight C++11 based 3D engine including tools
    - TDME2 is open source
      - please check the [license](https://github.com/andreasdr/tdme2/blob/master/LICENSE)
      - you find the source code at [https://github.com/andreasdr/tdme2](https://github.com/andreasdr/tdme2) 
      - you find binary alpha builds at [http://drewke.net/tdme2](http://drewke.net/tdme2)
      - you find developer documentation including collaboration graphs and private API as well as public API for current alpha build at [http://drewke.net/tdme2-documentation/alpha](http://drewke.net/tdme2-documentation/alpha)
        - RapidJSON is included, but not yet integrated into documentation, please see [http://rapidjson.org/](http://rapidjson.org/)

- What is already working
    - application
        - creates main window and initializes OpenGL/Vulkan context and does HID via GLUT or GLFW3
        - supports
          - setting window position and dimension
          - setting full screen or windowed, borderless windowed mode
          - setting application icon
          - setting mouse position and mouse cursor
          - executing other applications or background applications
          - swapping double buffered buffers (to screen) manually if required
          - checking if application is active (port-mingw, port-msc only for now)
        - provides
          - a crash handler for port-msc and port-mingw which also saves backtrace to crash.log
          - application life cycle
    - math
        - Math class with common math functions
        - Vector2, Vector3, Vector4, Matrix3x3, Matrix4x4 and Quaternion class
            - those have a ordinary API + operators, the latter is still a bit WIP
    - 3d engine
        - model parsing
            - DAE parsing with skinned meshes and animations
                - group names/ids must not have whitespace characters
                - requires baked matrices
                - requires triangulated meshes for now
            - FBX via FBX SDK
            - GLTF via tinygltf
            - TDME Model file format
                - this is a much more efficient model file format for TDME
                - can be read and written
        - objects/entity types
            - 3d model based objects with
                - animations
                    - supports model object base animation and animation overlays
                    - supports animation blending
                - skinning via
                    - CPU on GL2, GL3+/CORE, GLES2
                    - GPU via compute shaders with GL4.3+/CORE, Vulkan
                    - which also supports several instances of the same object to reduce compute and render calls
                - both animations and skinning have some sort of configurable LOD functionality
                - texture transformations/animations
                    - via texture matrices
            - objects with support for LOD
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
        - object/entity transformations
            - scaling
            - rotations
            - translation
        - color effects on objects/entities
            - color addition
            - color multiplication
        - lighting
            - supports phong lighting
            - supports phong shading on GL2, GL3+/CORE, 
            - supports gouraud shading on GLES2
            - supports diffuse mapping on GLES2, GL2, GL3+/CORE, Vulkan
            - supports specular shininess mapping on GL3+/CORE, Vulkan
            - supports normal mapping on GL3+/CORE, Vulkan
        - custum shaders that currently include
          - specular lighting + depth fog
          - specular lighting + foliage + depth fog
          - specular lighting + tree + depth fog
          - specular lighting + terrain + depth fog
          - specular lighting + water + depth fog(WIP)
          - sky(no lighting + no depth fog + fragment depth at maximum)
          - PBR lighting(WIP)
        - shadow mapping
        - early z rejection
        - post processing
          - depth blur
          - SSAO
        - object picking
        - camera control
          - set up look from, look at, up vector can be computed
          - frustum culling via oct tree
        - supports offscreen instances
            - rendering can be captured as screenshot
            - rendering can be used (in other engine instances) as diffuse texture
        - supports down/up scaled rendering of main engine
        - screenshot ability
        - multiple renderer
          - GLES2, GL2, GL3+/CORE and Vulkan(still experimental)
    - physics via ReactPhysics3D 0.7.0
        - have sphere, capsule, obb, convex mesh, concave terrain mesh bounding volumes
        - have multiple bounding volumes per body
        - have static, dynamic rigid bodies and collision bodies
        - uses discrete collision detection
        - rigid body simulator
        - ray tracing
        - for RP3D internals and additional features see ReactPhysics3D website
    - path finding/flow maps
        - uses A*
        - is paired with physics world to determine if a "cell" is walkable
        - optional custom walkable test
        - path finding utility supports generating flow maps
    - 3d audio
        - decoder
          - ogg vorbis decoder
        - audio entities
          - streams
          - sounds
    - GUI system
        - borrows some ideas from Nifty-GUI regarding XML and layouting
        - borrows some ideas from AngularJS like
            - all nodes are in the GUI node tree and can be made visible or unvisible depending on conditions
        - adds some improvements like
            - support auto keyword with nodes width and height attributes
            - layouting on demand in combination with conditions
        - supported primitive nodes from which compounds are built of
            - element
            - image
            - input
            - layout
            - panel
            - scrollbars
            - space
            - text + multiline text
        - supports custom templates and compound elements defined by templates and its controllers
            - compound elements
                - button
                - checkbox
                - dropdown
                - image button
                - input
                - knob
                - progress bar
                - radio button
                - scrollarea both
                - scrollarea horizontal
                - scrollarea vertical
                - selectbox
                - selectbox multiple
                - slider horizontal
                - slider vertical
                - tabs
            - supports custom templates in general
            - supports overriding used template of a compound element while using its controller
            - so TDME2 GUI is fully customizable in terms of appearance by modifying or adding XML template definitions
        - includes a simple script language
            - to react on events with like on-mouse-click, ... and on-change for elements
            - to manipulate conditions of elements, values of element controller and node properties
        - supports position and color based effects
    - Networking module, which consists of
        - UDP server
            - n:m threading model with non blocked IO via kernel event mechanismns(epoll, kqueue or select)
            - supports safe messages with acknowledgment and automatic resending
            - support fast messages
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
            - barrier
            - condition
            - consumer/producer queue
            - mutex
            - read write lock
            - semaphore
            - thread
    - Installer
        - TDME2 itself and TDME2 applications can be installed with TDME2 installer, which supports
            - offline installations
            - installation using HTTP download from a repository which is easy to set up
            - updating/repairing/uninstalling
        - TDME2 tools contains the installer creation application, whereas
            - installer definitions are set up using simple property files
            - create-installer is able to group files into components

- What does it (maybe still) lack
    - physics
      - some more RP3D integration
    - example games
    - documentation

- What is WIP or planned
    - Shader parameters
    - PBR lighting shader for GL3/CORE+
    - Makefile generator for TDME2 based projects
    - Installer for MacOSX
    - Integrate Haxe via HashLink to be able to script TDME2 applications or sub logics
    - Water shader
    - Improve on Vulkan
    - Expose shader and post processing programs setup API
    - Some UI elements need some default skinning fixes
    - A release plan
    - A demonstration video

- Technology
    - designed for simple multi threading, but
        - 3D rendering engine uses multiple threads if using Vulkan renderer, or one thread only if using a GL renderer
        - UDP client has its own thread
        - UDP server can have multiple IO threads, multiple worker threads and always has its own server thread
        - HTTP download client has its own thread
        - physics or game mechanics can also run in a separate thread(s)
    - uses 3rd party libraries
    	- need to be installed 
            - GLUT(for most platforms)
            - OpenGL
            - OpenAL
            - glew
            - pthreads
            - Vulkan(optional)
            - GLFW3(default on FreeBSD, Windows/MINGW, Linux, required for Vulkan)
        - included in TDME2 repository
            - FBXSDK
            - Hashlink
            - libpng
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
              - spirv
              - VulkanMemoryAllocator
            - zlib
    - targeted platforms and its current state
        - Windows/MINGW(port completed)
        - Windows/MSC(port completed)
        - Linux(port completed)
        - Mac Os X(port completed)
        - FreeBSD(port completed)
        - NetBSD(port completed)
        - OpenBSD(port is WIP)
        - Haiku(port completed)
        - Android(port pending)
        - iOS(port pending)

- Links
    - TDME2 Engine, see [README.md](./README.md)
    - TDME2 Model Editor, see [README-ModelEditor.md](./README-ModelEditor.md)
    - TDME2 Particle System Editor, see [README-ParticleSystemEditor.md](./README-ParticleSystemEditor.md)
    - TDME2 Level Editor, see [README-LevelEditor.md](./README-LevelEditor.md)
    - TDME2 How to build, see [README-BuildingHowTo.md](./README-BuildingHowTo.md)

- External references
    - "ReactPhysics3D" physics library, [http://www.reactphysics3d.com](http://www.reactphysics3d.com) 
    - the world wide web! thank you for sharing, see [README-WebReferences.md](./README-WebReferences.md)

- Other credits
    - Mathias Lenz
    - Dominik Hepp
    - Kolja Gumpert
    - Mathias Wenzel
    - Sergiu Crăiţoiu
    - Chantal Zabel
    - others

- Interested in collaboration? Then drop me a line via mail or use the [issues section on tdme2@github](https://github.com/andreasdr/tdme2/issues)
    - You can help with testing and reporting bugs 
    - I have easy to hard task regarding engine/tools development
    - I have tasks regarding documentation
    - I even might have system administrator tasks
    - If interested to get involved as software architect, I am currently looking for someone to review/improve parts of the architecture

- I have to pay my bills and beer, so if you have any use for this open source project, like educational, productive or fun, ..., consider a donation here https://www.paypal.me/andreasdrewke

![LOGO](https://raw.githubusercontent.com/andreasdr/tdme2/master/resources/logo/tdme_logo_full.png)

<span align="center">
    <a href="https://scan.coverity.com/projects/andreasdr-tdme2">
        <img alt="Coverity Scan Build Status" src="https://scan.coverity.com/projects/15611/badge.svg" />
    </a>
<span

- What is TDME2?
    - ThreeDeeMiniEngine2 is a lightweight C++11 based 3D engine including tools
    - TDME2 is open source
      - please check the [license](https://github.com/andreasdr/tdme2/blob/master/LICENSE) and the [licenses of used 3rd party libraries](https://github.com/andreasdr/tdme2/blob/master/ext)
      - you find the source code at [https://github.com/andreasdr/tdme2](https://github.com/andreasdr/tdme2) 
      - you find binary alpha builds at [http://drewke.net/tdme2](http://drewke.net/tdme2)
      - you find developer documentation for current alpha build at [http://drewke.net/tdme2-documentation/alpha](http://drewke.net/tdme2-documentation/alpha) including collaboration graphs and private API

- What is already working
    - 3d engine
        - model parsing
            - WaveFront OBJ
            - DAE parsing with skinned meshes and animations
                - group names/ids must not have whitespace characters
                - requires baked matrices
            - FBX via FBX SDK
            - TDME Model file format
                - this is a much more efficient model file format for TDME
                - can be read and written
            - DAE and WaveFront OBJ files require triangulated meshes for now
        - animations
            - supports model object base animation and animation overlays
            - supports animation blending when switching base animations
        - skinning via
            - CPU on GL2, GL3+/CORE, GLES2
            - GPU via compute shaders with GL4.3+/CORE, Vulkan
        - object transformations
            - scaling
            - rotations
            - translation
        - color effects on objects, particles, ...
            - color addition
            - color multiplication
        - texture transformations/animations
            - via texture matrices
        - lighting
            - supports phong lighting
            - supports phong shading on GL2, GL3+/CORE, 
            - supports gouraud shading on GLES2
            - supports diffuse mapping on GLES2, GL2, GL3+/CORE, Vulkan
            - supports specular shininess mapping on GL3+/CORE, Vulkan
            - supports normal mapping on GL3+/CORE, Vulkan
        - custum shaders that currently include
          - lighting + depth fog
          - lighting + foliage + depth fog
          - lighting + terrain + depth fog
          - solid(no lighting + no depth fog)
          - sky(no lighting + no depth fog + fragment depth at maximum)
        - shadow mapping
        - post processing
          - depth blur
          - SSAO 
        - particle system which
          - is object based
          - or point based
          - and supports
            - basic/point emitter
            - sphere emitter
            - bounding box emitter
            - circle on plane emitter
            - ...
          - there is also support for particle system groups
        - objects with support for LOD
        - objects with support for render groups for foliage and such
        - object picking
        - camera control
          - set up look from, look at, up vector can be computed
          - frustum culling via oct tree
        - supports offscreen instances
            - rendering can be captured as screenshot
            - rendering can be used (in other engine instances) as diffuse texture
        - screenshot ability
        - multiple renderer
          - GLES2, GL2, GL3+/CORE and Vulkan(still experimental)
    - physics via ReactPhysics3D 0.7.0
        - have sphere, capsule, obb, convex mesh, concave terrain mesh bounding volumes
        - have multiple bounding volumes per body
        - have static, dynamic rigid bodies and collision bodies
        - uses discrete collision detection
        - rigid body simulator
        - for RP3D internals and additional features see ReactPhysics3D website
    - path finding
        - uses A*
        - is paired with physics world to determine if a "cell" is walkable
        - optional custom walkable test
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
        - supported compound elements
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

- What does it (maybe still) lack
    - physics
      - some more RP3D integration
    - example games
    - documentation

- What is WIP or planned
    - Improve on Vulkan
    - PBR lighting shader for GL3/CORE+
    - simple script language for GUI
    - Expose shader and post processing programs setup API
    - Some UI elements need some default skinning fixes
    - WaveFront OBJ model file reader is broken currently
    - Integrate a scripting language to be able to script TDME2 applications or sub logics
    - Build documentation
    - Public API documentation
    - A release plan
    - A demonstration video

- Technology
    - designed for simple multi threading, but
        - 3D rendering engine uses 4 threads if using Vulkan renderer, or one thread only if using a GL renderer
        - UDP client has its own thread
        - UDP server can have multiple IO threads, multiple worker threads and always has its own server thread
        - physics or game mechanics can also run in a separate thread(s)
    - uses 3rd party libraries
    	- need to be installed 
            - GLUT
            - OpenGL
            - OpenAL
            - glew
            - pthreads
            - Vulkan(optional)
            - GLFW3(optional, required for Vulkan)
        - included in TDME2 repository
            - Vorbis/OGG
            - JsonBox
            - zlib
            - libpng
            - tinyxml
            - ReactPhysics3D
            - FBXSDK
            - V-HACD
            - glslang
            - OGLCompilersDLL
            - spirv
            - MoltenVK
    - targeted platforms and its current state
        - Windows/MINGW(port completed)
        - Windows/MSC(port completed)
        - Linux(port completed)
        - Mac Os X(port completed)
        - FreeBSD(port completed)
        - NetBSD(port completed)
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
    - the world wide web! thank you for sharing

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

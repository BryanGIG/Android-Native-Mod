## Android Native Mod Template

A minimal native only template for Android modding.

### Background

Recently i wanted to begin doing again some Android modding, but i didn't want to use any of the
existing frameworks, since it messy and i don't like it.
</br>So i created this template to make it easier for me to start a new project.

### How To Use

1. Clone the repo
2. Open the project in Android Studio / Visual Studio Code
3. Change the package name in `app/build.gradle` and library name
   in `app/src/main/cpp/CMakeLists.txt`
4. Start coding
5. Build the project
6. Copy the generated .so from `app/build/outputs/native/{debug/release}/lib{template}.so`
7. Load the library in your modded app
   </br>You can use many various methods to load the library, see [Injecting the library](#injecting-the-library)

### Injecting the library
This project is merely a template, so you can use any method you want to load the library.</br>
Here are some examples: </br></br>
Note: Modify "**template**" to your library name

- #### [Android-Ptrace-Injector - reveny](https://github.com/reveny/Android-Ptrace-Injector)
```bash
./Injector -p "com.target.package" -l "template"
```

- #### [System.loadLibrary](https://docs.oracle.com/javase/8/docs/api/java/lang/System.html#loadLibrary-java.lang.String)
```java
const-string v0, "template"

invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

- #### [xDL - hexhacking](https://github.com/hexhacking/xDL)
```c
void* handle = xdl_open("template", RTLD_NOW);
```

- #### Other methods
As long as you can load the library into the target process, you can use any method you want.

### To-Do
- [x] Polymorphism design pattern
- [x] Unity API (Vector2, Vector3, Quaternion, etc)
- [x] Doc: How to use
- [ ] Doc: What need to be changed
- [ ] Doc: What each file does
- [ ] Doc: How to add new functions
- [ ] Doc: How to add new classes

### Credit

- [Dobby](https://github.com/jmpews/Dobby) - Hooking library
- [KittyMemory](https://github.com/MJx0/KittyMemory) - Android, IOS runtime code patching library

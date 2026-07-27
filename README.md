# FirstGameSDL

A small C++/SDL2 rendering prototype. The current program opens an 800x600
window, draws `assets/player.png` at a larger destination rectangle, and moves
the texture horizontally across the screen. It is an early learning project,
not a complete game with levels, scoring, or player input.

## Current Behavior

- Creates a window titled `salvee` in windowed mode.
- Uses an SDL renderer and clears the frame to white.
- Loads `assets/player.png` through SDL_image and renders it at 384x256.
- Moves the texture horizontally at one logical unit per update and reverses
  direction at the current position limits.
- Caps the main loop at approximately 60 frames per second.
- Exits when the window close event is received. No keyboard or mouse controls
  are currently active; the commented-out code mentioning Escape is not part of
  the running behavior.

The source contains commented OpenGL setup examples, but the active rendering
path uses `SDL_Renderer`. OpenGL is not currently an active dependency of the
program.

## Dependencies

The source includes SDL2 and SDL2_image headers and links against SDL2 and
SDL2_image in the checked-in Windows VS Code build task. A working build also
requires:

- A C++ compiler compatible with the project, such as MinGW-w64 on Windows.
- SDL2 development headers and libraries.
- SDL2_image development headers and libraries.
- The corresponding runtime DLLs available beside the executable when running
  the Windows build.

The VS Code configuration points to MinGW-w64 and SDL2 2.0.14 installed at
Windows-specific paths. Those paths are configuration examples, not portable
dependency management.

## Build And Run

There is no currently verified portable build command. The root `Makefile`
references `src/Include`, `src/lib`, and a root-level `main.cpp`, none of which
match the checked-in `Src/` layout. Running `make` in the repository currently
fails because that `main.cpp` path does not exist.

The checked-in VS Code task documents the intended Windows build setup:

1. Install MinGW-w64 and SDL2/SDL2_image development packages.
2. Update the paths in `.vscode/tasks.json` if the tools are installed
   elsewhere.
3. Run the `SDL2` build task from the repository root. It is configured to
   compile the source files and write `build/game.exe`.
4. Run `build\\game.exe` from the repository root so the relative asset path
   `assets/player.png` resolves correctly.

The repository contains Windows build artifacts and DLLs under `build/`, plus
`libjpeg-9.dll` at the repository root. Their presence is recorded here for
orientation only; this project documentation does not claim that those
artifacts have been executed or are current.

## Repository Structure

```text
Src/
  main.cpp              # Application entry point and frame-limited loop
  Game.cpp/.hpp         # SDL window, events, update, render, and cleanup
  TextureManager.cpp/.hpp
                        # SDL_image loading helper
assets/
  player.png            # 96x64 RGBA player texture
build/                  # Checked-in Windows executable and runtime DLLs
.vscode/                # Windows MinGW build and debug configurations
Makefile                # Legacy, currently non-working build recipe
```

## Project Status And Limitations

This is an early SDL2 prototype intended to demonstrate a basic game loop,
texture loading, and 2D rendering. It currently has no gameplay objective,
input system, audio, animation system, collision handling, or portable build
configuration.

The code also has limited runtime error handling: initialization, texture
loading, and renderer operations are not consistently checked before use.
The build metadata should be aligned with the actual `Src/` directory before a
reproducible public build can be documented.

## Contributing

Issues and pull requests are welcome. Before submitting a change:

1. Describe the behavior or build issue being addressed.
2. Keep changes focused and update this README when supported commands or
   runtime behavior changes.
3. Verify the relevant build or runtime path on the target platform and state
   what was tested.

There is no separate contribution guide or automated test suite in this
repository yet.

## License

No `LICENSE` file or explicit license declaration is currently included. Do not
assume that the code or asset may be reused or redistributed without the
author's permission. Add a license file before publishing the project for
third-party reuse.

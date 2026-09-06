# BadBotEditor Plugin

A custom C++ **Editor Mode** plugin (`UEdMode` / `FEdMode`) for Unreal Engine 5 designed to accelerate level editing, viewport interactions, and asset handling.

---
## 🚀 Setup & Installation

1. Copy or clone the **BadBotEditor** directory into your Unreal Engine project's `Plugins/` folder:
   ```bash
   YourProject/
   └── Plugins/
       └── BadBotEditor/
2. Right-click your project's .uproject file in File Explorer and select Generate Visual Studio project files.

3. Open the .sln file in Visual Studio or Rider and compile the solution under the Development Editor configuration.

4. Launch the project, go to Edit > Plugins, and ensure BadBotEditor is checked/enabled

## 🛠️ Included Tools

### 🟢 Completed Tools

* **Material Copy-Paste Tool:** Allows level designers and environment artists to instantly sample and assign materials directly in the viewport, bypassing manual Details panel navigation.
  * **Controls:** Hold down `M` (default key) + **Right Click** on a static mesh to copy its material. Hold down `M` + **Left Click** on a target static mesh to paste.
  * **Custom Keybindings:** Uses an engine command wrapper (`FUICommandInfo`), allowing users to rebind the activation key in Unreal's Editor Preferences.
  * **Architecture:** Decoupled into its own dedicated tool class rather than crammed into the core editor mode class, keeping the plugin modular and scalable.
  * **Safety & UX:** Features full Undo/Redo transaction support (`FScopedTransaction`) and real-time feedback using the Slate notification library.

## 📂 Module Architecture

```text
BadBotEditor/
├── Source/
│   ├── BadBotEditor/       # Core Editor Mode logic & tools
│   │   ├── Public/
│   │   └── Private/
│   └── BadBotShared/       # Shared utility modules (Slate notifications, style sets)
│       ├── Public/
│       └── Private/
├── Resources/              # Icons and UI style assets
└── BadBotEditor.uplugin    # Plugin Descriptor

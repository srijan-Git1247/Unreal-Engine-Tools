


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

**Prerequisite:** Select BadBot Editor Mode from the Editor Modes panel (Shift + 2 or via the Mode Toolbar) to activate the tool set

**🟢Material Copy-Paste Tool:** Quickly copy and paste materials between objects directly in the viewport without digging through the Details panel.

<video src="https://github.com/user-attachments/assets/13e80b64-adae-44ab-82d8-2ff5aa28bd89" width="200" height="200" controls></video>

* **Controls:** Copy: Hold M + Right-Click on a mesh. Paste: Hold M + Left-Click on a target mesh.
* **Custom Shortcuts:** Change the default M key anytime in Unreal's Editor Preferences.
* **Full Undo/Redo:** Fully supports Ctrl + Z (FScopedTransaction) so you can undo accidental pastes.
* **Clean Design:** Built in its own standalone C++ class to keep the code clean and modular.
* **Slate Notification Helper (BadBotShared):** A reusable helper library that displays on-screen toast messages (green checkmarks for success, red X's for errors) to give instant feedback for editor actions.

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

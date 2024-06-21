# 🎥🚀 GStreamer Pipeline and Face Detection Project

Welcome to the GStreamer and OpenCV face detection project! Follow these steps to set up and run the project seamlessly. Let's dive in! 🌊

## 🌟 Part 1: GStreamer Pipeline

### 📜 Step-by-Step Guide:

1. **Navigate to the Directory**:
   ```sh
   cd 1_stream_to_frames
   ```

2. **Run the Shell Script**:
   Pass two command-line arguments:
   - `argv[1]`: Path to the mp4 file (e.g., `./sample_video/sample_1.mp4`)
   - `argv[2]`: Name of the output folder (e.g., `out_1` for `sample_1.mp4` and `out_1_2` for `sample_3.mp4`)

   Your command will look something like this:
   ```sh
   ./stream_to_frames.sh ./sample_video/sample_1.mp4 out_1
   ```
   🎉 The output will be in the same directory with the name you specified!

---

## 🌟 Part 2: C++ Application for Face Detection

### 📜 Step-by-Step Guide:

1. **Navigate to the Directory**:
   ```sh
   cd 2_CaptureFaces
   ```

2. **Build the Project**:
   ```sh
   cmake .
   ```
   This command will build the Visual Studio Solution.

3. **Customizing Input Directory** (if needed):
   - Open `CMakeLists.txt` in a file editor.
   - Locate the line:
     ```cmake
     set_target_properties(CaptureFaces PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "../1_stream_to_frames/out_1_2/")
     ```
   - Change the command-line argument to your desired input directory. For example, to take input from `out_1`:
     ```cmake
     set_target_properties(CaptureFaces PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "../1_stream_to_frames/out_1/")
     ```
   - Save and exit the editor.

4. **Open in Visual Studio**:
   - Open the `CaptureFaces.sln` file in Visual Studio.
   - 🎨✨ Voilà! You now have the C++ Application project ready to go!

---

## 🚀 Let's Make It Happen!

### 🛠️ Requirements:

- **GStreamer**: Ensure you have GStreamer installed on your system.
- **OpenCV**: Make sure OpenCV is installed and properly configured.

### 💡 Tips:

- **Ensure Dependencies**: Double-check that all dependencies are installed and configured correctly.
- **Test Video**: Use a sample video to verify that everything is working as expected.
- **Explore OpenCV**: Dive into OpenCV documentation to learn more about face detection and other exciting features!

### 🎯 Goal:

- **Stream and Scale Video**: Use GStreamer to read an MP4 video file, scale it down to 640x640 resolution, and write JPEG encoded frames.
- **Detect and Crop Faces**: Use OpenCV’s pre-trained XML classifier to detect faces from each JPEG frame and crop them. Create a frame-wise folder structure of cropped faces.

---

Happy coding! 🌟 If you encounter any issues or have questions, feel free to reach out. Let's detect some faces! 😎📸

---
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

cv::CascadeClassifier face_cascade;
std::string face_cascade_name = "C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml";

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image_directory>\n";
        return -1;
    }

    std::string image_directory = argv[1];
    std::string all_im_path = image_directory + "*.jpeg";

    std::vector<cv::String> image_files;
    cv::glob(all_im_path, image_files, false);

    if (!face_cascade.load(face_cascade_name)) {
        std::cerr << "Error loading cascade classifier.\n";
        return -1;
    }

    for (const auto& file : image_files) {
        cv::Mat frame = cv::imread(file);
        if (frame.empty()) {
            continue;
        }

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0, cv::Size(20, 20));

        if (faces.empty()) {
            continue;
        }

        fs::path output_dir = fs::current_path() / "OUTPUT" / std::to_string(std::distance(image_files.begin(), std::find(image_files.begin(), image_files.end(), file)));
        fs::create_directories(output_dir);

        for (size_t i = 0; i < faces.size(); ++i) {
            cv::Rect& face = faces[i];
            cv::Mat face_crop = frame(face);
            cv::Mat resized_face;
            cv::resize(face_crop, resized_face, cv::Size(128, 128), 0, 0, cv::INTER_LINEAR);

            std::ostringstream filename;
            filename << output_dir.string() << "\\" << i << ".jpeg";
            cv::imwrite(filename.str(), resized_face);
        }
    }

    return 0;
}

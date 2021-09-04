#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <cwchar>
#include <fstream>
#include <opencv2/opencv.hpp>
class ascii_art
{
private:
	cv::Mat _image{0};
	int _type_process{0};
	std::string ascii;

public:
	ascii_art(const std::string, const int);
	void show_ascii_art();
	void console_font_size(int, int) noexcept;
	void gray_scale() noexcept;
	std::string char_ascii(int) noexcept;
	inline void intensity();
	void resize(int, int) noexcept;
	void ascii_file(std::string) noexcept;
};

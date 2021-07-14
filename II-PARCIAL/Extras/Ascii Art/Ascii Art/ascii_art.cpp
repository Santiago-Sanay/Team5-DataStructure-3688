#include "ascii_art.h"
#pragma warning(disable : 4996)

ascii_art::ascii_art(const std::string src, const int type_process)
	: _image(cv::imread(src)), _type_process(type_process)
{
}

void ascii_art::show_ascii_art()
{
	ascii_art::intensity();
}

void ascii_art::console_font_size(int x, int y) noexcept
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = x;
	cfi.dwFontSize.Y = y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void ascii_art::gray_scale() noexcept
{
	cv::Mat _grey_image;
	cv::cvtColor(_image, _grey_image, cv::COLOR_BGR2GRAY);
	_image = _grey_image;
}

inline void ascii_art::intensity()
{
	double unit = (256.0 + 1) / 68.0;
	int cn = _image.channels();
	std::string str;
	uint8_t *pixelPtr = (uint8_t *)_image.data;
	cv::Scalar_<uint8_t> bgrPixel;
	for (int i = 0; i < _image.rows; i++)
	{
		for (int j = 0; j < _image.cols; j++)
		{
			int R = pixelPtr[i * _image.cols * cn + j * cn + 2];
			int G = pixelPtr[i * _image.cols * cn + j * cn + 1];
			int B = pixelPtr[i * _image.cols * cn + j * cn + 0];
			int grayScaleValue = (B * 0.0722) + // B
								 (G * 0.7152) + // G
								 (R * 0.2126);	// R
			int intensity = grayScaleValue / unit;
			str = char_ascii(intensity);
			ascii += str;
			printf("\033[%d;2;%d;%d;%dm%c\033[0;00m", _type_process, R, G, B, str[0]);
		}
		ascii += "\n";
		std::cout << std::endl;
	}
}

void ascii_art::resize(int x, int y) noexcept
{
	cv::Mat resizeImage;
	cv::resize(_image, resizeImage, cv::Size(x, y));
	_image = resizeImage;
}

void ascii_art::ascii_file(std::string name) noexcept
{
	std::ofstream file;
	file.open(name);
	if (file.is_open())
		file << ascii;

	file.close();
}


std::string ascii_art::char_ascii(int intensity) noexcept
{
	std::vector<std::string> map{
		"$", "@", "B", "%", "8", "&", "W", "M", "#", "*", "o", "a", "h", "k", "b", "d", "p", "q", "w", "m", "Z",
		"O", "0", "Q", "L", "C", "J", "U", "Y", "X", "z", "c", "v", "u", "n", "x", "r", "j", "f", "t", "/", "\\",
		"|", "(", ")", "1", "{", "}", "[", "]", "?", "-", "_", "+", "~", "<", ">", "i", "!", "l",
		"I", ";", ":", "\"", "^", "`", "'", "."};
	return map[intensity];
}

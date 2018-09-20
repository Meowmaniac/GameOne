#include "QButton.h"

QButton::QButton(bool isRight)
{
	isRight = isRight;
}

QButton::~QButton()
{
}

Button* QButton::create()
{
	return this;
}

bool QButton::init(const std::string &normalImage, const std::string& rightImage, const std::string& failImage, const std::string& disableImage, TextureResType texType)
{
	bool ret = true;
	do
	{
		if (!Widget::init())
		{
			ret = false;
			break;
		}
		if(isRight)
			this->loadTextures(normalImage, rightImage, disableImage, texType);
		else
			this->loadTextures(normalImage, failImage, disableImage, texType);
	} while (0);
	return ret;
}

void QButton::setImgPaths(const std::string & normalImage, const std::string & rightImage, const std::string & failImage, const std::string & disableImage)
{
	paths.push_back(normalImage);
	paths.push_back(rightImage);
	paths.push_back(failImage);
	paths.push_back(disableImage);
}


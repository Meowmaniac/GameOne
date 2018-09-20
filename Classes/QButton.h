#ifndef __QBUTTON_H__
#define __QBUTTON_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <iostream>
#include <vector>
#include <string>

using namespace cocos2d;
using namespace ui;

class QButton : public ui::Button
{
public:
	QButton(bool isRight);
	~QButton();
	Button* create();
	bool init(const std::string &normalImage, const std::string& rightImage, const std::string& failImage, const std::string& disableImage, TextureResType texType);
	void setImgPaths(const std::string &normalImage, const std::string& rightImage, const std::string& failImage, const std::string& disableImage);

private:
	bool isRight;
	std::vector<String> paths;
};

#endif // __QBUTTON_H__
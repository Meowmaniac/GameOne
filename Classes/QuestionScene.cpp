#include "QuestionScene.h"
#include "ui\CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene* QuestionScene::createScene()
{
	auto scene = Scene::create();
	auto layer = QuestionScene::create();
	scene->addChild(layer);

	return scene;
}

bool QuestionScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// add background"
	auto sprite = Sprite::create("res/BGquestion.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

	// add answers buttons
	// Нужно придумать как связать их положение и размер относительно поля вопроса !!!
	int marginH = 30, marginW = 50; // отступ от края экрана для кнопок
	char* answerA = "A: ";
	char* answerB = "B: ";
	char* answerC = "C: ";
	char* answerD = "D: ";
	// добавить дописывание вариантов ответов из текущего вопроса

	auto buttonA = Button::create("res/Qfield.png", "res/Qfield.png", "res/Qfield.png");
	buttonA->setPosition(Vec2(marginW, marginH + marginH /2 + buttonA->getContentSize().height));
	buttonA->setAnchorPoint(Vec2(0, 0));
	buttonA->setTitleText(answerA);
	buttonA->setTitleFontSize(30.0);
	buttonA->setTitleAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);

	auto buttonB = Button::create("res/Qfield.png", "res/Qfield.png", "res/Qfield.png");
	buttonB->setPosition(Vec2(visibleSize.width + origin.x - marginW, origin.y + marginH + marginH / 2 + buttonA->getContentSize().height));
	buttonB->setAnchorPoint(Vec2(1, 0));
	buttonB->setTitleText(answerB);
	buttonB->setTitleFontSize(30.0);
	buttonB->setTitleAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);

	auto buttonC = Button::create("res/Qfield.png", "res/Qfield.png", "res/Qfield.png");
	buttonC->setPosition(Vec2(marginW, marginH));
	buttonC->setAnchorPoint(Vec2(0, 0));
	buttonC->setTitleText(answerC);
	buttonC->setTitleFontSize(30.0);
	buttonC->setTitleAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);

	auto buttonD = Button::create("res/Qfield.png", "res/Qfield.png", "res/Qfield.png");
	buttonD->setPosition(Vec2(visibleSize.width + origin.x - marginW, marginH));
	buttonD->setAnchorPoint(Vec2(1, 0));
	buttonD->setTitleText(answerD);
	buttonD->setTitleFontSize(30.0);
	buttonD->setTitleAlignment(TextHAlignment::LEFT, TextVAlignment::CENTER);

	this->addChild(buttonA, 1);
	this->addChild(buttonB, 1);
	this->addChild(buttonC, 1);
	this->addChild(buttonD, 1);

	// add text of question background and label
	auto questionBG = Sprite::create("res/TextField.png");
	questionBG->setAnchorPoint(Vec2(0.5, 0));
	questionBG->setPosition(Vec2(origin.x + visibleSize.width / 2, buttonA->getContentSize().height*2 + marginH*2 + origin.y));
	questionBG->setScaleY(0.5);
	questionBG->setScaleX(0.775); // Проверить что будет при изменении разрешения

	this->addChild(questionBG, 1);

	char* questionText = u8"Какого Спирита пока еще в Dota 2 не существует ?";
	auto questionLabel = Label::createWithTTF(questionText, "fonts/arial.ttf", 40);
	questionLabel->setLineBreakWithoutSpace(true);
	//questionLabel->setAnchorPoint(Vec2(0, 1));
	questionLabel->setDimensions(questionBG->getBoundingBox().size.width, questionBG->getBoundingBox().size.height);
	questionLabel->setPositionX(questionBG->getPositionX());
	questionLabel->setPositionY(questionBG->getPositionY() + questionBG->getBoundingBox().size.height / 2); // разобраться с тем какие нужны отступы
	questionLabel->setAlignment(TextHAlignment::CENTER, TextVAlignment::CENTER);

	QuestionScene::initQuestion(questionLabel, buttonA, buttonB, buttonC, buttonD);

	this->addChild(questionLabel, 2);

	return true;
}

void QuestionScene::initQuestion(Label * qtext, Button * ansA, Button * ansB, Button * ansC, Button * ansD)
{
	// С помощью парсера считываем вопрос из соответствующей категории и назначаем его текст
	// и текст ответов Label и Buttons соответственно
	tinyxml2::XMLDocument qdoc("res/questions.xml");
	
	if (!qdoc.LoadFile())
	{
		std::cout << "File is not opened" << endl;
	}
	std::string text = qdoc.FirstChildElement("Question")->FirstChildElement("Text")->GetText();
	std::cout << text;
}
/*
// Класс ответа. Создан чтобы отслеживать состояние правильный/неправильный
// Возможно не нужен
Answer::Answer(bool isR, std::string txt)
{
	isRight = isR;
	text = txt;
}

Answer::~Answer()
{
}
*/
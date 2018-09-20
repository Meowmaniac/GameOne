#pragma once
#include "cocos2d.h"
#include "tinyxml2.h"
#include "ui\CocosGUI.h"
#include <iostream> // для тестов

USING_NS_CC;
using namespace ui;


class QuestionScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	std::string qText;
	void QuestionScene::initQuestion(Label * qtext, Button * ansA, Button * ansB, Button * ansC, Button * ansD);
	
	CREATE_FUNC(QuestionScene);
};
/*
// Класс ответа. Создан чтобы отслеживать состояние правильный/неправильный
class Answer
{
public:
	Answer(bool isR, std::string txt);
	~Answer();
private:
	bool isRight;
	std::string text;
};*/
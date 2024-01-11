#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
	, leftButton(false)
	, color({ 0,0,0 })
	, size(3)
	, surprise(false)
	, verifyOutsideWindow(false)
	, surpriseStatus({ 255,0,0 })
	, xpos(100)
	, ypos(650)
	, xRect(100)
	, yRect(100)
	, colors({ {160,160,164},{255,0,0},{0,255,0},{0,0,255},{255,128,0},{255,128,192},{255,255,0},{185,122,87},{255,255,255},{0,0,0} })
	, widths({ 3, 5,10, 15 })
	, borders({ {100,100}, {100, 500}, {900, 100}, {900, 500} })
	, gameState(ConvertStringToGameState("MainMenu"))
	, reg(false)
{
	bigLogo = new QLabel(this);
	bigLogo->setPixmap(QPixmap("images//big_logo.png"));
	logo = new QLabel(this);
	logo->setPixmap(QPixmap("images//logoTTP.png"));
	ui->setupUi(this);
	ui->guessList->setFocusPolicy(Qt::NoFocus);
	setFocusPolicy(Qt::StrongFocus);
	setVisibilities(ConvertStringToGameState("MainMenu"));
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), SLOT(createThread()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
	if (gameState == ConvertStringToGameState("InGame"))
	{
		if (e->button() == Qt::LeftButton && e->pos().x() > xpos && e->pos().x() < xpos + 30 * (colors.size() + 1) && e->pos().y() > ypos && e->pos().y() < ypos + 30)
		{
			if ((e->pos().x() - xpos) / 30 == colors.size())
				surprise = true;
			else
			{
				color = colors[(e->pos().x() - xpos) / 30];
				surprise = false;
			}
		}
		if (e->button() == Qt::LeftButton && e->pos().x() > xpos && e->pos().x() < xpos + 30 * (widths.size()) && e->pos().y() > ypos + 30 && e->pos().y() < ypos + 60)
			size = widths[(e->pos().x() - xpos) / 30];
		if (e->button() == Qt::LeftButton && e->pos().x() > 100 && e->pos().x() < 900 && e->pos().y() > 100 && e->pos().y() < 500)
		{
			leftButton = true;

			if (!surprise)
				points.push_back({ e->pos(), color, size, true });
			else
			{
				colorChange(e);
				std::get<3>(points[points.size() - 1]) = true;
			}
			update();
		}
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{
	if (gameState == ConvertStringToGameState("InGame"))
	{
		if (leftButton)
		{
			actionHistory.push(points.size() - 1);
			leftButton = false;
		}
		verifyOutsideWindow = false;
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
	if (gameState == ConvertStringToGameState("InGame"))
		if (leftButton)
		{
			if (e->pos().x() > 100 && e->pos().x() < 900 && e->pos().y() > 100 && e->pos().y() < 500)
			{
				if (!surprise)
				{
					points.push_back({ e->pos(), color, size, verifyOutsideWindow });
				}
				else
					colorChange(e);
				verifyOutsideWindow = false;
			}
			else
				verifyOutsideWindow = true;
			update();
		}
}

void MainWindow::paintEvent(QPaintEvent* e)
{
	QPainter p(this);
	QPen pen;
	QBrush brush;
	if (gameState == ConvertStringToGameState("MeetingRoom"))
	{
		for (int i = 0; i < players.size(); i++)
		{
			QRect r(xRect, yRect, 150, 50);
			QString s = QString::fromStdString(players[i]);
			pen.setWidth(1);
			pen.setColor({ 0,0,0 });
			brush.setColor({ 255,255,255 });
			brush.setStyle(Qt::SolidPattern);
			p.setBrush(brush);
			p.setPen(pen);
			p.drawRect(r);
			p.drawText(r, Qt::AlignCenter, s);
			yRect += 50;
		}
		yRect -= 50 * players.size();
	}
	if (gameState == ConvertStringToGameState("InGame"))
	{
		for (int i = 0; i < colors.size(); i++)
		{
			QRect r(xpos, ypos, 30, 30);
			pen.setWidth(1);
			pen.setColor({ 0,0,0 });
			brush.setColor(colors[i]);
			brush.setStyle(Qt::SolidPattern);
			p.setBrush(brush);
			p.setPen(pen);
			p.drawRect(r);
			if (i < widths.size())
			{
				QRect r(xpos, ypos + 30, 30, 30);
				pen.setWidth(1);
				pen.setColor({ 0,0,0 });
				p.setBrush(Qt::white);
				p.setPen(pen);
				p.drawRect(r);
				r = { xpos + 15 - widths[i] / 2, ypos + 45 - widths[i] / 2, widths[i], widths[i] };
				p.setBrush(Qt::black);
				p.setPen(pen);
				p.drawEllipse(r);
			}
			xpos += 30;
		}
		QRect r(xpos, ypos, 30, 30);
		pen.setWidth(1);
		pen.setColor({ 0,0,0 });
		p.setBrush(Qt::white);
		p.setPen(pen);
		p.drawRect(r);
		p.drawText(r, Qt::AlignCenter, "?");
		xpos -= 30 * colors.size();
		QRect border(borders[0].x(), borders[0].y(), borders[3].x() - borders[0].x(), borders[3].y() - borders[0].y());
		p.drawRect(border);
		for (int index = 0; index < points.size(); index++)
		{
			if (index == 0)
			{
				pen.setColor(std::get<1>(points[index]));
				pen.setWidth(std::get<2>(points[index]));
				p.setPen(pen);
				p.drawPoint(std::get<0>(points[index]));
			}
			else
			{
				if (std::get<1>(points[index]) != std::get<1>(points[index - 1]))
				{
					pen.setColor(std::get<1>(points[index]));
					p.setPen(pen);
				}
				if (std::get<2>(points[index]) != std::get<2>(points[index - 1]))
				{
					pen.setWidth(std::get<2>(points[index]));
					p.setPen(pen);
				}
			}
			if (index != 0)
			{
				if (std::get<3>(points[index]) == false)
					p.drawLine(std::get<0>(points[index - 1]), std::get<0>(points[index]));
				else
					p.drawPoint(std::get<0>(points[index]));
			}
		}
		pen.setWidth(17);
		pen.setColor(Qt::black);
		p.setPen(pen);
		p.drawLine(borders[0], borders[1]);
		p.drawLine(borders[0], borders[2]);
		p.drawLine(borders[1], borders[3]);
		p.drawLine(borders[2], borders[3]);
	}
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Return)
	{
		if (gameState == ConvertStringToGameState("LoginOrRegister"))
		{
			ui->usernameExists->setVisible(false);
			if (ui->username->text().isEmpty() || noText(ui->username->text()))
			{
				ui->emptyUsername->setVisible(true);
				ui->notRegistered->setVisible(false);
				ui->userRegistered->setVisible(false);
				ui->wrongPassowrd->setVisible(false);
			}
			else
				ui->emptyUsername->setVisible(false);
			if (ui->password->text().isEmpty())
			{
				ui->emptyPassword->setVisible(true);
				ui->userRegistered->setVisible(false);
				ui->wrongPassowrd->setVisible(false);
				ui->notRegistered->setVisible(false);
			}
			else
				ui->emptyPassword->setVisible(false);
			if (!(ui->username->text().isEmpty() || noText(ui->username->text())) && !ui->password->text().isEmpty())
			{
				auto response = cpr::Get(cpr::Url{ "http://localhost:13034/users" });
				auto users = crow::json::load(response.text);
				bool userExists = false;
				if (reg)
				{
					for (const auto& user : users)
						if (user["username"] == ui->username->text().toStdString())
						{
							userExists = true;
							ui->usernameExists->setVisible(true);
							break;
						}
					auto response2 = cpr::Put(
						cpr::Url{ "http://localhost:13034/addUser" },
						cpr::Payload{
							{ "username", ui->username->text().toStdString()},
							{ "password", password.toStdString()}
						}
					);
					if (!userExists)
					{
						ui->userRegistered->setVisible(true);
					}
					else
					{
						ui->userRegistered->setVisible(false);
					}
					ui->username->clear();
					ui->password->clear();
				}
				else
				{
					for (const auto& user : users)
						if (user["username"] == ui->username->text().toStdString())
						{
							userExists = true;
							ui->notRegistered->setVisible(false);
							if (user["password"] == password.toStdString())
							{
								gameState = ConvertStringToGameState("LoggedIn");
								setVisibilities(gameState);
								ui->username->clear();
								ui->password->clear();
								username = user["username"].s();
							}
							else
							{
								ui->password->clear();
								ui->wrongPassowrd->setVisible(true);
							}
							break;
						}
					if (!userExists)
					{
						ui->username->clear();
						ui->password->clear();
						ui->wrongPassowrd->setVisible(false);
						ui->notRegistered->setVisible(true);
					}
					update();
				}
			}
		}
		if (gameState == ConvertStringToGameState("EnterCode"))
		{
			roomcode = ui->roomCode->text().toStdString();
			auto responseGames = cpr::Get(cpr::Url{ "http://localhost:13034/games" });
			auto responsePlayers = cpr::Get(cpr::Url{ "http://localhost:13034/" + ui->roomCode->text().toStdString() + "/players" });
			auto responseSettings = cpr::Get(cpr::Url{ "http://localhost:13034/" + ui->roomCode->text().toStdString() + "/settings" });
			auto games = crow::json::load(responseGames.text);
			auto players = crow::json::load(responsePlayers.text);
			auto settings = crow::json::load(responseSettings.text);
			//bool existaJoc-false
			for (const auto& game : games)
				if (game["roomcode"] == ui->roomCode->text().toStdString())
					if (players["noPlayers"].i() < settings["maxNoPlayers"].i() + 1)
					{

						auto responseAddPlayer = cpr::Put(
							cpr::Url{ "http://localhost:13034/addPlayer" },
							cpr::Payload{
								{ "roomcode", ui->roomCode->text().toStdString()},
								{ "user", username}
							});
						ui->generatedCodeLabel->setText(ui->roomCode->text());
						host = false;
						ui->timeChoice->setEnabled(false);
						ui->languageChoice->setEnabled(false);
						ui->noPlayersChoice->setEnabled(false);
						ui->noWordsChoice->setEnabled(false);
						ui->hintsChoice->setEnabled(false);
						ui->roundsChoice->setEnabled(false);
						gameState = ConvertStringToGameState("MeetingRoom");
						setVisibilities(gameState);
						GetPlayersInRoom();
						timer->start(100);
						//existaJoc-true
						break;
					}
					else
						ui->roomFull->setVisible(true);

			ui->roomCode->clear();
			//daca existaJoc-false atunci afisezi eroarea;clear la casuta
			update();
		}
		if (gameState == ConvertStringToGameState("MeetingRoom") || gameState == ConvertStringToGameState("InGame"))
			if (!(ui->guess->text().isEmpty()) && !noText(ui->guess->text()) && ui->guess->hasFocus())
			{
				userGuess = QString::fromStdString(username) + ": " + ui->guess->text();
				auto response = cpr::Put(
					cpr::Url{ "http://localhost:13034/addGuess" },
					cpr::Payload{
						{ "roomcode", roomcode},
						{ "guess", userGuess.toStdString()}
					});
				QtConcurrent::run([this]() {GetGuessesInChat(); });
				timer->start(100);
				ui->guess->clear();
			}
	}
}

void MainWindow::colorChange(QMouseEvent* e)
{
	bool oneAction = false;
	if (surpriseStatus.red() == 255 && surpriseStatus.green() != 255 && surpriseStatus.blue() == 0 && oneAction == false)
	{
		surpriseStatus.setGreen(surpriseStatus.green() + 15);
		oneAction = true;
	}
	if (surpriseStatus.red() != 0 && surpriseStatus.green() == 255 && surpriseStatus.blue() == 0 && oneAction == false)
	{
		surpriseStatus.setRed(surpriseStatus.red() - 15);
		oneAction = true;
	}
	if (surpriseStatus.red() == 0 && surpriseStatus.green() == 255 && surpriseStatus.blue() != 255 && oneAction == false)
	{
		surpriseStatus.setBlue(surpriseStatus.blue() + 15);
		oneAction = true;
	}
	if (surpriseStatus.red() == 0 && surpriseStatus.green() != 0 && surpriseStatus.blue() == 255 && oneAction == false)
	{
		surpriseStatus.setGreen(surpriseStatus.green() - 15);
		oneAction = true;
	}
	if (surpriseStatus.red() != 255 && surpriseStatus.green() == 0 && surpriseStatus.blue() == 255 && oneAction == false)
	{
		surpriseStatus.setRed(surpriseStatus.red() + 15);
		oneAction = true;
	}
	if (surpriseStatus.red() == 255 && surpriseStatus.green() == 0 && surpriseStatus.blue() != 0 && oneAction == false)
	{
		surpriseStatus.setBlue(surpriseStatus.blue() - 15);
		oneAction = true;
	}
	points.push_back({ e->pos(),surpriseStatus,size,verifyOutsideWindow });
}

bool MainWindow::noText(QString text)
{
	bool isEmpty = true;
	for (int index = 0; index < text.size(); index++)
	{
		if (text[index] != ' ')
			isEmpty = false;
	}
	return isEmpty;
}

void MainWindow::setVisibilities(GameState state)
{
	if (state == ConvertStringToGameState("MainMenu"))
	{
		setStyleSheet("QMainWindow {background: url(images//background.png)}");
		bigLogo->setGeometry(700, 200, 400, 300);
		bigLogo->setScaledContents(true);
		bigLogo->setVisible(true);
		logo->setVisible(false);
		ui->roundsChoice->setVisible(false);
		ui->roundsLabel->setVisible(false);
		ui->hintsChoice->setVisible(false);
		ui->hintsLabel->setVisible(false);
		ui->noPlayersChoice->setVisible(false);
		ui->noPlayersLabel->setVisible(false);
		ui->noWordsChoice->setVisible(false);
		ui->noWordsLabel->setVisible(false);
		ui->languageChoice->setVisible(false);
		ui->languageLabel->setVisible(false);
		ui->timeChoice->setVisible(false);
		ui->timeLabel->setVisible(false);
		ui->startButton->setVisible(false);
		ui->errorLabel->setVisible(false);
		ui->guess->setVisible(false);
		ui->guessList->setVisible(false);
		ui->emptyUsername->setVisible(false);
		ui->emptyPassword->setVisible(false);
		ui->clearButton->setVisible(false);
		ui->undoButton->setVisible(false);
		ui->usernameLabel->setVisible(false);
		ui->username->setVisible(false);
		ui->passwordLabel->setVisible(false);
		ui->password->setVisible(false);
		ui->createButton->setVisible(false);
		ui->joinButton->setVisible(false);
		ui->signOutButton->setVisible(false);
		ui->backButton->setVisible(false);
		ui->roomCode->setVisible(false);
		ui->codeLabel->setVisible(false);
		ui->loginButton->setVisible(true);
		ui->registerButton->setVisible(true);
		ui->loginText->setVisible(false);
		ui->registerText->setVisible(false);
		ui->usernameExists->setVisible(false);
		ui->wrongPassowrd->setVisible(false);
		ui->notRegistered->setVisible(false);
		ui->userRegistered->setVisible(false);
		ui->enterCodeTextLabel->setVisible(false);
		ui->generatedCodeLabel->setVisible(false);
		ui->roomFull->setVisible(false);

	}
	if (state == ConvertStringToGameState("LoginOrRegister"))
	{
		ui->backButton->setVisible(true);
		ui->usernameLabel->setVisible(true);
		ui->username->setVisible(true);
		ui->passwordLabel->setVisible(true);
		ui->password->setVisible(true);
		ui->loginButton->setVisible(false);
		ui->registerButton->setVisible(false);
		ui->enterCodeTextLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("LoggedIn"))
	{
		ui->signOutButton->setVisible(true);
		ui->createButton->setVisible(true);
		ui->joinButton->setVisible(true);
		ui->usernameLabel->setVisible(false);
		ui->username->setVisible(false);
		ui->passwordLabel->setVisible(false);
		ui->password->setVisible(false);
		ui->backButton->setVisible(false);
		ui->loginText->setVisible(false);
		ui->wrongPassowrd->setVisible(false);
		ui->notRegistered->setVisible(false);
		ui->enterCodeTextLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("EnterCode"))
	{
		ui->roomCode->setVisible(true);
		ui->codeLabel->setVisible(true);
		ui->createButton->setVisible(false);
		ui->joinButton->setVisible(false);
		ui->signOutButton->setVisible(false);
		ui->backButton->setVisible(false);
		ui->enterCodeTextLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("MeetingRoom"))
	{
		ui->roundsChoice->setVisible(true);
		ui->roundsLabel->setVisible(true);
		ui->hintsChoice->setVisible(true);
		ui->hintsLabel->setVisible(true);
		ui->noPlayersChoice->setVisible(true);
		ui->noPlayersLabel->setVisible(true);
		ui->noWordsChoice->setVisible(true);
		ui->noWordsLabel->setVisible(true);
		ui->languageChoice->setVisible(true);
		ui->languageLabel->setVisible(true);
		ui->timeChoice->setVisible(true);
		ui->timeLabel->setVisible(true);
		if (host)
			ui->startButton->setVisible(true);
		ui->guess->setVisible(true);
		ui->guessList->setVisible(true);
		ui->generatedCodeLabel->setVisible(true);
		ui->enterCodeTextLabel->setVisible(true);
		ui->createButton->setVisible(false);
		ui->joinButton->setVisible(false);
		ui->signOutButton->setVisible(false);
		ui->roomCode->setVisible(false);
		ui->codeLabel->setVisible(false);
		ui->roomFull->setVisible(false);
	}
	if (state == ConvertStringToGameState("InGame"))
	{
		logo->setGeometry(5, 5, 100, 98);
		logo->setScaledContents(true);
		logo->setVisible(true);
		ui->clearButton->setVisible(true);
		ui->undoButton->setVisible(true);
		bigLogo->setVisible(false);
		ui->roundsChoice->setVisible(false);
		ui->roundsLabel->setVisible(false);
		ui->hintsChoice->setVisible(false);
		ui->hintsLabel->setVisible(false);
		ui->noPlayersChoice->setVisible(false);
		ui->noPlayersLabel->setVisible(false);
		ui->noWordsChoice->setVisible(false);
		ui->noWordsLabel->setVisible(false);
		ui->languageChoice->setVisible(false);
		ui->languageLabel->setVisible(false);
		ui->timeChoice->setVisible(false);
		ui->timeLabel->setVisible(false);
		ui->startButton->setVisible(false);
		ui->errorLabel->setVisible(false);
		ui->generatedCodeLabel->setVisible(false);
		ui->enterCodeTextLabel->setVisible(false);


	}

}

void MainWindow::clear()
{
	if (!points.empty())
	{
		previousDrawings.push(points);
		points.clear();
		actionHistory.push(-1);
		update();
	}
}

void MainWindow::undo()
{
	if (actionHistory.empty())
		return;
	else
		if (actionHistory.size() == 1)
		{
			points.clear();
			actionHistory.pop();
		}
		else
			if (actionHistory.top() == -1)
			{
				points = previousDrawings.top();
				previousDrawings.pop();
				actionHistory.pop();
			}
			else
			{
				int lastUndoPoint = actionHistory.top();
				actionHistory.pop();
				for (int index = lastUndoPoint; index > actionHistory.top(); index--)
					points.erase(points.begin() + index);
			}
	update();
}

void MainWindow::on_startButton_clicked()
{
	if (ui->roundsChoice->currentText() != '-' && ui->hintsChoice->currentText() != '-' && ui->noPlayersChoice->currentText() != '-' &&
		ui->noWordsChoice->currentText() != '-' && ui->languageChoice->currentText() != '-' && ui->timeChoice->currentText() != '-')
	{
		gameState = ConvertStringToGameState("InGame");
		setVisibilities(gameState);
		update();
	}
	else
		ui->errorLabel->setVisible(true);
}


void MainWindow::on_createButton_clicked()
{
	roomcode = GenerateCode();
	ui->generatedCodeLabel->setText(QString::fromStdString(roomcode));
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:13034/addGame" },
		cpr::Payload{
			{ "roomcode", roomcode},
			{ "user", username}
		}
	);
	host = true;
	ui->timeChoice->setEnabled(true);
	ui->languageChoice->setEnabled(true);
	ui->noPlayersChoice->setEnabled(true);
	ui->noWordsChoice->setEnabled(true);
	ui->hintsChoice->setEnabled(true);
	ui->roundsChoice->setEnabled(true);
	gameState = ConvertStringToGameState("MeetingRoom");
	setVisibilities(gameState);
	GetPlayersInRoom();
	timer->start(100);
	update();
}


void MainWindow::on_joinButton_clicked()
{
	gameState = ConvertStringToGameState("EnterCode");
	setVisibilities(gameState);
	update();
}


void MainWindow::on_clearButton_clicked()
{
	clear();
}

void MainWindow::on_undoButton_clicked()
{
	undo();
}

void MainWindow::on_loginButton_clicked()
{
	gameState = ConvertStringToGameState("LoginOrRegister");
	setVisibilities(gameState);
	ui->loginText->setVisible(true);
	update();
	reg = false;
}

void MainWindow::on_registerButton_clicked()
{
	gameState = ConvertStringToGameState("LoginOrRegister");
	setVisibilities(gameState);
	ui->registerText->setVisible(true);
	update();
	reg = true;
}

void MainWindow::on_signOutButton_clicked()
{
	gameState = ConvertStringToGameState("MainMenu");
	setVisibilities(gameState);
	ui->username->clear();
	ui->password->clear();
	update();
}

void MainWindow::on_backButton_clicked()
{
	gameState = ConvertStringToGameState("MainMenu");
	setVisibilities(gameState);
	ui->username->clear();
	ui->password->clear();
	update();
}

void MainWindow::on_password_textChanged()
{
	if (password.size() < ui->password->text().size())
		password = password + ui->password->text()[ui->password->text().size() - 1];
	else
		password.resize(ui->password->text().size());
	QString stars;
	for (int index = 0; index < password.size(); index++)
		stars = stars + '*';
	ui->password->setText(stars);
}

void MainWindow::createThread()
{
	QtConcurrent::run([this]() {GetPlayersInRoom(); });
	if (!host)
		QtConcurrent::run([this]() {GetSettings(); });
	QtConcurrent::run([this]() {GetGuessesInChat(); });
}

void MainWindow::GetPlayersInRoom()
{
	std::string url = "http://localhost:13034/" + roomcode + "/players";
	auto response = cpr::Get(cpr::Url{ url });
	auto playerList = crow::json::load(response.text);
	if (players.size() != playerList["noPlayers"].i())
		for (int index = players.size(); index < playerList["noPlayers"].i(); index++)
		{
			std::string key = "user" + std::to_string(index);
			players.push_back(playerList[key].s());
			update();
		}
}

void MainWindow::GetSettings()
{
	std::string url = "http://localhost:13034/" + roomcode + "/settings";
	auto response = cpr::Get(cpr::Url{ url });
	auto roomSettings = crow::json::load(response.text);
	ui->timeChoice->setCurrentIndex(roomSettings["time"].i());
	ui->languageChoice->setCurrentIndex(roomSettings["language"].i());
	ui->noPlayersChoice->setCurrentIndex(roomSettings["maxNoPlayers"].i());
	ui->noWordsChoice->setCurrentIndex(roomSettings["noWords"].i());
	ui->hintsChoice->setCurrentIndex(roomSettings["hints"].i());
	ui->roundsChoice->setCurrentIndex(roomSettings["noRounds"].i());
}

void MainWindow::GetGuessesInChat()
{
	std::string url = "http://localhost:13034/" + roomcode + "/guesses";
	auto response = cpr::Get(cpr::Url{ url });
	auto guessList = crow::json::load(response.text);
	if (ui->guessList->count() != guessList["noGuesses"].i())
		for (int index = ui->guessList->count(); index < guessList["noGuesses"].i(); index++)
		{
			std::string key = "guess" + std::to_string(index);
			std::string text = guessList[key].s();
			replaceCharacters(text);
			ui->guessList->addItem(QString::fromStdString(text));
		}
}

void MainWindow::modifySettings()
{
	if (host)
	{
		if (players.size() > ui->noPlayersChoice->currentIndex())
			ui->noPlayersChoice->setCurrentIndex(players.size() - 1);

		auto response = cpr::Put(
			cpr::Url{ "http://localhost:13034/modifySettings" },
			cpr::Payload{
				{ "roomcode", roomcode},
				{ "time", std::to_string(ui->timeChoice->currentIndex())},
				{ "language", std::to_string(ui->languageChoice->currentIndex())},
				{ "noPlayers", std::to_string(ui->noPlayersChoice->currentIndex())},
				{ "noWords", std::to_string(ui->noWordsChoice->currentIndex())},
				{ "hints", std::to_string(ui->hintsChoice->currentIndex())},
				{ "noRounds", std::to_string(ui->roundsChoice->currentIndex())}
			});
	}
}

void MainWindow::replaceCharacters(std::string& text)
{
	for (int index = 0; index < text.size(); index++)
	{
		if (text[index] == '%')
		{
			if (text[index + 1] == '2' && text[index + 2] == '0')
				text.replace(index, 3, " ");
			if (text[index + 1] == '2' && text[index + 2] == '1')
				text.replace(index, 3, "!");
			if (text[index + 1] == '3' && text[index + 2] == 'F')
				text.replace(index, 3, "?");
			if (text[index + 1] == '2' && text[index + 2] == 'C')
				text.replace(index, 3, ",");
			if (text[index + 1] == '2' && text[index + 2] == 'A')
				text.replace(index, 3, "*");
			if (text[index + 1] == '3' && text[index + 2] == 'A')
				text.replace(index, 3, ":");
			if (text[index + 1] == '2' && text[index + 2] == '8')
				text.replace(index, 3, "(");
			if (text[index + 1] == '2' && text[index + 2] == '9')
				text.replace(index, 3, ")");
			if (text[index + 1] == '5' && text[index + 2] == 'E')
				text.replace(index, 3, "^");
		}
	}
}

uint16_t MainWindow::GenerateRandomNumber(uint16_t min, uint16_t max)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<uint16_t> distribution(min, max);
	int randomValue = distribution(generator);
	return randomValue;
}

std::string MainWindow::GenerateCode()
{
	std::string code;
	int x;
	for (int i = 0;i < 6;i++)
	{
		x = GenerateRandomNumber(1, 3);
		if (x == 1)
			code.push_back(char(GenerateRandomNumber(48, 57)));
		else if (x == 2)
			code.push_back(char(GenerateRandomNumber(65, 90)));
		else
			code.push_back(char(GenerateRandomNumber(97, 122)));
	}
	return code;
}

void MainWindow::on_timeChoice_currentTextChanged()
{
	modifySettings();
}

void MainWindow::on_languageChoice_currentTextChanged()
{
	modifySettings();
}

void MainWindow::on_noPlayersChoice_currentTextChanged()
{
	modifySettings();
}

void MainWindow::on_noWordsChoice_currentTextChanged()
{
	modifySettings();
}

void MainWindow::on_hintsChoice_currentTextChanged()
{
	modifySettings();
}

void MainWindow::on_roundsChoice_currentTextChanged()
{
	modifySettings();
}
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
	, m_leftButton(false)
	, m_color({ 0,0,0 })
	, m_size(3)
	, m_surprise(false)
	, m_verifyOutsideWindow(false)
	, m_surpriseStatus({ 255,0,0 })
	, m_xpos(100)
	, m_ypos(650)
	, m_xRect(100)
	, m_yRect(100)
	, m_colors({ {160,160,164},{255,0,0},{0,255,0},{0,0,255},{255,128,0},{255,128,192},{255,255,0},{185,122,87},{255,255,255},{0,0,0} })
	, m_widths({ 3, 5,10, 15 })
	, m_borders({ {100,100}, {100, 500}, {900, 100}, {900, 500} })
	, m_gameState(ConvertStringToGameState("MainMenu"))
	, m_reg(false)
	, m_host(false)
	, m_chosen(false)
	, m_wordX(150)
	, m_wordY(350)
{
	m_bigLogo = new QLabel(this);
	m_bigLogo->setPixmap(QPixmap("images//big_logo.png"));
	m_logo = new QLabel(this);
	m_logo->setPixmap(QPixmap("images//logoTTP.png"));
	m_ui->setupUi(this);
	m_ui->guessList->setFocusPolicy(Qt::NoFocus);
	setFocusPolicy(Qt::StrongFocus);
	SetVisibilities(ConvertStringToGameState("MainMenu"));
	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), SLOT(CreateThread()));
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::mousePressEvent(QMouseEvent* e)
{
	if (m_gameState == ConvertStringToGameState("InGame"))
	{
		if (!m_chosen)
		{
			for (int i = 0; i < m_words.size(); i++)
				if (e->button() == Qt::LeftButton && e->pos().x() > m_wordX + 200 * i && e->pos().x() < m_wordX + 200 * i + 150 && e->pos().y() > m_wordY && e->pos().y() < m_wordY + 30)
				{
					m_chosenWord = m_words[i];
					m_chosen = true;
				}
			for (int i = 0; i < m_customWords.size(); i++)
				if (e->button() == Qt::LeftButton && e->pos().x() > m_wordX + 200 * i && e->pos().x() < m_wordX + 200 * i + 150 && e->pos().y() > m_wordY+100 && e->pos().y() < m_wordY + 130)
				{
					m_chosenWord = m_customWords[i];
					m_chosen = true;
				}
			QtConcurrent::run([this]() {
				auto timerResponse = cpr::Put(
					cpr::Url{ "http://localhost:13034/runTimer" },
					cpr::Payload{
						{ "roomcode", m_roomcode }
					});
				});
			update();
		}
		else
		{
			if (e->button() == Qt::LeftButton && e->pos().x() > m_xpos && e->pos().x() < m_xpos + 30 * (m_colors.size() + 1) && e->pos().y() > m_ypos && e->pos().y() < m_ypos + 30)
			{
				if ((e->pos().x() - m_xpos) / 30 == m_colors.size())
					m_surprise = true;
				else
				{
					m_color = m_colors[(e->pos().x() - m_xpos) / 30];
					m_surprise = false;
				}
			}
			if (e->button() == Qt::LeftButton && e->pos().x() > m_xpos && e->pos().x() < m_xpos + 30 * (m_widths.size()) && e->pos().y() > m_ypos + 30 && e->pos().y() < m_ypos + 60)
				m_size = m_widths[(e->pos().x() - m_xpos) / 30];
			if (e->button() == Qt::LeftButton && e->pos().x() > 100 && e->pos().x() < 900 && e->pos().y() > 100 && e->pos().y() < 500)
			{
				m_leftButton = true;

				if (!m_surprise)
				{
					m_points[m_points.size()] = { static_cast<uint16_t>(e->pos().x()), static_cast<uint16_t>(e->pos().y()),
						static_cast<uint8_t>(m_color.red()), static_cast<uint8_t>(m_color.green()),
						static_cast<uint8_t>(m_color.blue()), static_cast<uint8_t>(m_size), true };
					int lastPoint = m_points.size() - 1;
					QtConcurrent::run([this, lastPoint]() {
						auto response = cpr::Put(
							cpr::Url{ "http://localhost:13034/addPoints" },
							cpr::Payload{
								{ "roomcode", m_roomcode},
								{ "xCoord", std::to_string(m_points[lastPoint].GetX())},
								{ "yCoord", std::to_string(m_points[lastPoint].GetY())},
								{ "rColor", std::to_string(m_points[lastPoint].GetRed())},
								{ "gColor", std::to_string(m_points[lastPoint].GetGreen())},
								{ "bColor", std::to_string(m_points[lastPoint].GetBlue())},
								{ "brushSize", std::to_string(m_points[lastPoint].GetBrushSize())},
								{ "inWindow", std::to_string(m_points[lastPoint].GetInWindow())},
								{ "indexPoint", std::to_string(lastPoint)}
							});
						});
				}
				else
				{
					ColorChange(e);
					m_points[m_points.size() - 1].SetInWindow(true);
					int lastPoint = m_points.size() - 1;
					QtConcurrent::run([this, lastPoint]() {
						auto response = cpr::Put(
							cpr::Url{ "http://localhost:13034/addPoints" },
							cpr::Payload{
								{ "roomcode", m_roomcode},
								{ "xCoord", std::to_string(m_points[lastPoint].GetX())},
								{ "yCoord", std::to_string(m_points[lastPoint].GetY())},
								{ "rColor", std::to_string(m_points[lastPoint].GetRed())},
								{ "gColor", std::to_string(m_points[lastPoint].GetGreen())},
								{ "bColor", std::to_string(m_points[lastPoint].GetBlue())},
								{ "brushSize", std::to_string(m_points[lastPoint].GetBrushSize())},
								{ "inWindow", std::to_string(m_points[lastPoint].GetInWindow())},
								{ "indexPoint", std::to_string(lastPoint)}
							});
						});
				}
				update();
			}
		}
	}
}

void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{
	if (m_gameState == ConvertStringToGameState("InGame"))
	{
		if (m_leftButton)
		{
			m_actionHistory.push(m_points.size() - 1);
			m_leftButton = false;
		}
		m_verifyOutsideWindow = false;
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
	if (m_gameState == ConvertStringToGameState("InGame"))
	{
		if (m_leftButton)
		{
			if (e->pos().x() > 100 && e->pos().x() < 900 && e->pos().y() > 100 && e->pos().y() < 500)
			{
				if (!m_surprise)
				{
					m_points[m_points.size()] = { static_cast<uint16_t>(e->pos().x()), static_cast<uint16_t>(e->pos().y()),
						static_cast<uint8_t>(m_color.red()), static_cast<uint8_t>(m_color.green()),
						static_cast<uint8_t>(m_color.blue()), static_cast<uint8_t>(m_size), m_verifyOutsideWindow };
					int lastPoint = m_points.size() - 1;
					QtConcurrent::run([this, lastPoint]() {
						auto response = cpr::Put(
							cpr::Url{ "http://localhost:13034/addPoints" },
							cpr::Payload{
								{ "roomcode", m_roomcode},
								{ "xCoord", std::to_string(m_points[lastPoint].GetX())},
								{ "yCoord", std::to_string(m_points[lastPoint].GetY())},
								{ "rColor", std::to_string(m_points[lastPoint].GetRed())},
								{ "gColor", std::to_string(m_points[lastPoint].GetGreen())},
								{ "bColor", std::to_string(m_points[lastPoint].GetBlue())},
								{ "brushSize", std::to_string(m_points[lastPoint].GetBrushSize())},
								{ "inWindow", std::to_string(m_points[lastPoint].GetInWindow())},
								{ "indexPoint", std::to_string(lastPoint)}
							});
						});
				}
				else
				{
					ColorChange(e);
					int lastPoint = m_points.size() - 1;
					QtConcurrent::run([this, lastPoint]() {
						auto response = cpr::Put(
							cpr::Url{ "http://localhost:13034/addPoints" },
							cpr::Payload{
								{ "roomcode", m_roomcode},
								{ "xCoord", std::to_string(m_points[lastPoint].GetX())},
								{ "yCoord", std::to_string(m_points[lastPoint].GetY())},
								{ "rColor", std::to_string(m_points[lastPoint].GetRed())},
								{ "gColor", std::to_string(m_points[lastPoint].GetGreen())},
								{ "bColor", std::to_string(m_points[lastPoint].GetBlue())},
								{ "brushSize", std::to_string(m_points[lastPoint].GetBrushSize())},
								{ "inWindow", std::to_string(m_points[lastPoint].GetInWindow())},
								{ "indexPoint", std::to_string(lastPoint)}
							});
						});
				}
				m_verifyOutsideWindow = false;
			}
			else
				m_verifyOutsideWindow = true;
			update();
		}
	}
}

void MainWindow::paintEvent(QPaintEvent* e)
{
	QPainter p(this);
	QPen pen;
	QBrush brush;
	if (m_gameState == ConvertStringToGameState("MeetingRoom"))
	{
		for (int i = 0; i < m_players.size(); i++)
		{
			QRect r(m_xRect, m_yRect, 150, 50);
			QString s = QString::fromStdString(m_players[i]);
			pen.setWidth(1);
			pen.setColor({ 0,0,0 });
			brush.setColor({ 255,255,255 });
			brush.setStyle(Qt::SolidPattern);
			p.setBrush(brush);
			p.setPen(pen);
			p.drawRect(r);
			p.drawText(r, Qt::AlignCenter, s);
			m_yRect += 50;
		}
		m_yRect -= 50 * m_players.size();
	}
	if (m_gameState == ConvertStringToGameState("InGame"))
	{
		if (!m_chosen)
		{
			for (int index = 0; index < m_words.size(); index++)
			{
				QRect r(m_wordX, m_wordY, 150, 30);
				QString s = QString::fromStdString(m_words[index]);
				pen.setWidth(1);
				pen.setColor({ 0,0,0 });
				brush.setColor({ 255,255,255 });
				brush.setStyle(Qt::SolidPattern);
				p.setBrush(brush);
				p.setPen(pen);
				p.drawRect(r);
				p.drawText(r, Qt::AlignCenter, s);
				m_wordX += 200;
			}
			m_wordY += 100;
			m_wordX -= 200 * m_words.size();
			for (int index = 0; index < 3; index++)
			{
				QRect r(m_wordX, m_wordY, 150, 30);
				QString s;
				pen.setWidth(1);
				pen.setColor({ 0,0,0 });
				brush.setColor({ 255,255,255 });
				brush.setStyle(Qt::SolidPattern);
				p.setBrush(brush);
				p.setPen(pen);
				p.drawRect(r);
				if (index == 0)
					s = "Buy word (-50p, hard)";
				if (index == 1)
					s = "Buy word (-100p, medium)";
				if (index == 2)
					s = "Buy word (-150p, easy)";
				p.drawText(r, Qt::AlignCenter, s);
				m_wordX += 200;
			}
			m_wordX -= 600;
			m_wordY -= 100;
		}
		else
		{
			for (int i = 0; i < m_colors.size(); i++)
			{
				QRect r(m_xpos, m_ypos, 30, 30);
				pen.setWidth(1);
				pen.setColor({ 0,0,0 });
				brush.setColor(m_colors[i]);
				brush.setStyle(Qt::SolidPattern);
				p.setBrush(brush);
				p.setPen(pen);
				p.drawRect(r);
				if (i < m_widths.size())
				{
					QRect r(m_xpos, m_ypos + 30, 30, 30);
					pen.setWidth(1);
					pen.setColor({ 0,0,0 });
					p.setBrush(Qt::white);
					p.setPen(pen);
					p.drawRect(r);
					r = { m_xpos + 15 - m_widths[i] / 2, m_ypos + 45 - m_widths[i] / 2, m_widths[i], m_widths[i] };
					p.setBrush(Qt::black);
					p.setPen(pen);
					p.drawEllipse(r);
				}
				m_xpos += 30;
			}
			QRect r(m_xpos, m_ypos, 30, 30);
			pen.setWidth(1);
			pen.setColor({ 0,0,0 });
			p.setBrush(Qt::white);
			p.setPen(pen);
			p.drawRect(r);
			p.drawText(r, Qt::AlignCenter, "?");
			m_xpos -= 30 * m_colors.size();
			QRect border(m_borders[0].x(), m_borders[0].y(), m_borders[3].x() - m_borders[0].x(), m_borders[3].y() - m_borders[0].y());
			p.drawRect(border);
			for (std::pair<int, Points> point : m_points)
			{
				Points prevPoint;
				if (m_points.find(point.first - 1) != m_points.end())
					prevPoint = m_points[point.first - 1];
				if (point.first == 0)
				{
					pen.setColor(QColor{ point.second.GetRed(), point.second.GetGreen(), point.second.GetBlue() });
					pen.setWidth(point.second.GetBrushSize());
					p.setPen(pen);
					p.drawPoint(QPoint{ point.second.GetX(), point.second.GetY() });
				}
				else
				{
					if (prevPoint == m_points[point.first - 1])
					{
						if (!point.second.SameColor(prevPoint))
						{
							pen.setColor(QColor{ point.second.GetRed(), point.second.GetGreen(), point.second.GetBlue() });
							p.setPen(pen);
						}
						if (point.second.GetBrushSize() != prevPoint.GetBrushSize())
						{
							pen.setWidth(point.second.GetBrushSize());
							p.setPen(pen);
						}
						if (point.second.GetInWindow() == false)
							p.drawLine(QPoint{ prevPoint.GetX(), prevPoint.GetY() }, QPoint{ point.second.GetX(), point.second.GetY() });
						else
							p.drawPoint(QPoint{ point.second.GetX(), point.second.GetY() });
					}
				}
			}
			pen.setWidth(17);
			pen.setColor(Qt::black);
			p.setPen(pen);
			p.drawLine(m_borders[0], m_borders[1]);
			p.drawLine(m_borders[0], m_borders[2]);
			p.drawLine(m_borders[1], m_borders[3]);
			p.drawLine(m_borders[2], m_borders[3]);
		}
	}
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Return)
	{
		if (m_gameState == ConvertStringToGameState("LoginOrRegister"))
		{
			m_ui->usernameExists->setVisible(false);
			if (m_ui->username->text().isEmpty() || NoText(m_ui->username->text()))
			{
				m_ui->emptyUsername->setVisible(true);
				m_ui->notRegistered->setVisible(false);
				m_ui->userRegistered->setVisible(false);
				m_ui->wrongPassowrd->setVisible(false);
			}
			else
				m_ui->emptyUsername->setVisible(false);
			if (m_ui->password->text().isEmpty())
			{
				m_ui->emptyPassword->setVisible(true);
				m_ui->userRegistered->setVisible(false);
				m_ui->wrongPassowrd->setVisible(false);
				m_ui->notRegistered->setVisible(false);
			}
			else
				m_ui->emptyPassword->setVisible(false);
			if (!(m_ui->username->text().isEmpty() || NoText(m_ui->username->text())) && !m_ui->password->text().isEmpty())
			{
				auto response = cpr::Get(cpr::Url{ "http://localhost:13034/users" });
				auto users = crow::json::load(response.text);
				bool userExists = false;
				if (m_reg)
				{
					for (const auto& user : users)
						if (user["username"] == m_ui->username->text().toStdString())
						{
							userExists = true;
							m_ui->usernameExists->setVisible(true);
							break;
						}
					auto response2 = cpr::Put(
						cpr::Url{ "http://localhost:13034/addUser" },
						cpr::Payload{
							{ "username", m_ui->username->text().toStdString()},
							{ "password", m_password.toStdString()}
						}
					);
					if (!userExists)
					{
						m_ui->userRegistered->setVisible(true);
					}
					else
					{
						m_ui->userRegistered->setVisible(false);
					}
					m_ui->username->clear();
					m_ui->password->clear();
				}
				else
				{
					for (const auto& user : users)
						if (user["username"] == m_ui->username->text().toStdString())
						{
							userExists = true;
							m_ui->notRegistered->setVisible(false);
							if (user["password"] == m_password.toStdString())
							{
								m_gameState = ConvertStringToGameState("LoggedIn");
								SetVisibilities(m_gameState);
								m_ui->username->clear();
								m_ui->password->clear();
								m_username = user["username"].s();
							}
							else
							{
								m_ui->password->clear();
								m_ui->wrongPassowrd->setVisible(true);
							}
							break;
						}
					if (!userExists)
					{
						m_ui->username->clear();
						m_ui->password->clear();
						m_ui->wrongPassowrd->setVisible(false);
						m_ui->notRegistered->setVisible(true);
					}
					update();
				}
			}
		}
		if (m_gameState == ConvertStringToGameState("EnterCode"))
		{
			m_roomcode = m_ui->roomCode->text().toStdString();
			auto responseGames = cpr::Get(cpr::Url{ "http://localhost:13034/games" });
			auto responsePlayers = cpr::Get(cpr::Url{ "http://localhost:13034/" + m_ui->roomCode->text().toStdString() + "/players" });
			auto responseSettings = cpr::Get(cpr::Url{ "http://localhost:13034/" + m_ui->roomCode->text().toStdString() + "/settings" });
			auto games = crow::json::load(responseGames.text);
			auto players = crow::json::load(responsePlayers.text);
			auto settings = crow::json::load(responseSettings.text);
			m_ui->roomFull->setVisible(false);
			m_ui->doesntExist->setVisible(false);
			bool gameExists = false;
			for (const auto& game : games)
				if (game["roomcode"] == m_ui->roomCode->text().toStdString())
				{
					gameExists = true;
					if (players["noPlayers"].i() < settings["maxNoPlayers"].i() + 1)
					{

						auto responseAddPlayer = cpr::Put(
							cpr::Url{ "http://localhost:13034/addPlayer" },
							cpr::Payload{
								{ "roomcode", m_ui->roomCode->text().toStdString()},
								{ "user", m_username}
							});
						m_ui->generatedCodeLabel->setText(m_ui->roomCode->text());
						m_host = false;
						m_ui->timeChoice->setEnabled(false);
						m_ui->languageChoice->setEnabled(false);
						m_ui->noPlayersChoice->setEnabled(false);
						m_ui->noWordsChoice->setEnabled(false);
						m_ui->hintsChoice->setEnabled(false);
						m_ui->roundsChoice->setEnabled(false);
						m_gameState = ConvertStringToGameState("MeetingRoom");
						SetVisibilities(m_gameState);
						GetPlayersInRoom();
						m_timer->start(100);
						break;
					}
					else
						m_ui->roomFull->setVisible(true);
				}
			if (!gameExists)
				m_ui->doesntExist->setVisible(true);

			m_ui->roomCode->clear();
			update();
		}
		if (m_gameState == ConvertStringToGameState("MeetingRoom") || m_gameState == ConvertStringToGameState("InGame"))
			if (!(m_ui->guess->text().isEmpty()) && !NoText(m_ui->guess->text()) && m_ui->guess->hasFocus())
			{
				m_userGuess = QString::fromStdString(m_username) + ": " + m_ui->guess->text();
				int countDifferentLetters = 0;
				std::string guess = m_userGuess.toStdString();
				if (m_ui->guess->text().size() == m_chosenWord.size())
					for (int i = 0; i < m_chosenWord.size(); i++)
						if (m_ui->guess->text().toStdString()[i] != m_chosenWord[i])
							countDifferentLetters++;
				if (countDifferentLetters == 1)
					m_userGuess = QString::fromStdString(m_username) + " is close!";
				if (m_ui->guess->text() == QString::fromStdString(m_chosenWord))
					m_userGuess = QString::fromStdString(m_username) + " guessed the word!";
				auto response = cpr::Put(
					cpr::Url{ "http://localhost:13034/addGuess" },
					cpr::Payload{
						{ "roomcode", m_roomcode},
						{ "guess", m_userGuess.toStdString()}
					});
				QtConcurrent::run([this]() {GetGuessesInChat(); });
				m_timer->start(100);
				m_ui->guess->clear();
			}
	}
}

void MainWindow::ColorChange(QMouseEvent* e)
{
	bool oneAction = false;
	if (m_surpriseStatus.red() == 255 && m_surpriseStatus.green() != 255 && m_surpriseStatus.blue() == 0 && oneAction == false)
	{
		m_surpriseStatus.setGreen(m_surpriseStatus.green() + 15);
		oneAction = true;
	}
	if (m_surpriseStatus.red() != 0 && m_surpriseStatus.green() == 255 && m_surpriseStatus.blue() == 0 && oneAction == false)
	{
		m_surpriseStatus.setRed(m_surpriseStatus.red() - 15);
		oneAction = true;
	}
	if (m_surpriseStatus.red() == 0 && m_surpriseStatus.green() == 255 && m_surpriseStatus.blue() != 255 && oneAction == false)
	{
		m_surpriseStatus.setBlue(m_surpriseStatus.blue() + 15);
		oneAction = true;
	}
	if (m_surpriseStatus.red() == 0 && m_surpriseStatus.green() != 0 && m_surpriseStatus.blue() == 255 && oneAction == false)
	{
		m_surpriseStatus.setGreen(m_surpriseStatus.green() - 15);
		oneAction = true;
	}
	if (m_surpriseStatus.red() != 255 && m_surpriseStatus.green() == 0 && m_surpriseStatus.blue() == 255 && oneAction == false)
	{
		m_surpriseStatus.setRed(m_surpriseStatus.red() + 15);
		oneAction = true;
	}
	if (m_surpriseStatus.red() == 255 && m_surpriseStatus.green() == 0 && m_surpriseStatus.blue() != 0 && oneAction == false)
	{
		m_surpriseStatus.setBlue(m_surpriseStatus.blue() - 15);
		oneAction = true;
	}
	m_points[m_points.size()] = { static_cast<uint16_t>(e->pos().x()), static_cast<uint16_t>(e->pos().y()),
		static_cast<uint8_t>(m_surpriseStatus.red()), static_cast<uint8_t>(m_surpriseStatus.green()),
		static_cast<uint8_t>(m_surpriseStatus.blue()),static_cast<uint8_t>(m_size),m_verifyOutsideWindow };
}

bool MainWindow::NoText(QString text)
{
	bool isEmpty = true;
	for (int index = 0; index < text.size(); index++)
	{
		if (text[index] != ' ')
			isEmpty = false;
	}
	return isEmpty;
}

void MainWindow::SetVisibilities(GameState state)
{
	if (state == ConvertStringToGameState("MainMenu"))
	{
		setStyleSheet("QMainWindow {background: url(images//background.png)}");
		m_bigLogo->setGeometry(700, 200, 400, 300);
		m_bigLogo->setScaledContents(true);
		m_bigLogo->setVisible(true);
		m_logo->setVisible(false);
		m_ui->roundsChoice->setVisible(false);
		m_ui->roundsLabel->setVisible(false);
		m_ui->hintsChoice->setVisible(false);
		m_ui->hintsLabel->setVisible(false);
		m_ui->noPlayersChoice->setVisible(false);
		m_ui->noPlayersLabel->setVisible(false);
		m_ui->noWordsChoice->setVisible(false);
		m_ui->noWordsLabel->setVisible(false);
		m_ui->languageChoice->setVisible(false);
		m_ui->languageLabel->setVisible(false);
		m_ui->timeChoice->setVisible(false);
		m_ui->timeLabel->setVisible(false);
		m_ui->startButton->setVisible(false);
		m_ui->errorLabel->setVisible(false);
		m_ui->guess->setVisible(false);
		m_ui->guessList->setVisible(false);
		m_ui->emptyUsername->setVisible(false);
		m_ui->emptyPassword->setVisible(false);
		m_ui->clearButton->setVisible(false);
		m_ui->undoButton->setVisible(false);
		m_ui->usernameLabel->setVisible(false);
		m_ui->username->setVisible(false);
		m_ui->passwordLabel->setVisible(false);
		m_ui->password->setVisible(false);
		m_ui->createButton->setVisible(false);
		m_ui->joinButton->setVisible(false);
		m_ui->signOutButton->setVisible(false);
		m_ui->backButton->setVisible(false);
		m_ui->roomCode->setVisible(false);
		m_ui->codeLabel->setVisible(false);
		m_ui->loginButton->setVisible(true);
		m_ui->registerButton->setVisible(true);
		m_ui->loginText->setVisible(false);
		m_ui->registerText->setVisible(false);
		m_ui->usernameExists->setVisible(false);
		m_ui->wrongPassowrd->setVisible(false);
		m_ui->notRegistered->setVisible(false);
		m_ui->userRegistered->setVisible(false);
		m_ui->enterCodeTextLabel->setVisible(false);
		m_ui->generatedCodeLabel->setVisible(false);
		m_ui->roomFull->setVisible(false);
		m_ui->doesntExist->setVisible(false);
		m_ui->notEnoughPlayers->setVisible(false);
		m_ui->timerLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("LoginOrRegister"))
	{
		m_ui->backButton->setVisible(true);
		m_ui->usernameLabel->setVisible(true);
		m_ui->username->setVisible(true);
		m_ui->passwordLabel->setVisible(true);
		m_ui->password->setVisible(true);
		m_ui->loginButton->setVisible(false);
		m_ui->registerButton->setVisible(false);
		m_ui->enterCodeTextLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("LoggedIn"))
	{
		m_ui->signOutButton->setVisible(true);
		m_ui->createButton->setVisible(true);
		m_ui->joinButton->setVisible(true);
		m_ui->usernameLabel->setVisible(false);
		m_ui->username->setVisible(false);
		m_ui->passwordLabel->setVisible(false);
		m_ui->password->setVisible(false);
		m_ui->backButton->setVisible(false);
		m_ui->loginText->setVisible(false);
		m_ui->wrongPassowrd->setVisible(false);
		m_ui->notRegistered->setVisible(false);
		m_ui->enterCodeTextLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("EnterCode"))
	{
		m_ui->roomCode->setVisible(true);
		m_ui->codeLabel->setVisible(true);
		m_ui->createButton->setVisible(false);
		m_ui->joinButton->setVisible(false);
		m_ui->signOutButton->setVisible(false);
		m_ui->backButton->setVisible(false);
		m_ui->enterCodeTextLabel->setVisible(false);

	}
	if (state == ConvertStringToGameState("MeetingRoom"))
	{
		m_ui->roundsChoice->setVisible(true);
		m_ui->roundsLabel->setVisible(true);
		m_ui->hintsChoice->setVisible(true);
		m_ui->hintsLabel->setVisible(true);
		m_ui->noPlayersChoice->setVisible(true);
		m_ui->noPlayersLabel->setVisible(true);
		m_ui->noWordsChoice->setVisible(true);
		m_ui->noWordsLabel->setVisible(true);
		m_ui->languageChoice->setVisible(true);
		m_ui->languageLabel->setVisible(true);
		m_ui->timeChoice->setVisible(true);
		m_ui->timeLabel->setVisible(true);
		if (m_host)
			m_ui->startButton->setVisible(true);
		m_ui->guess->setVisible(true);
		m_ui->guessList->setVisible(true);
		m_ui->generatedCodeLabel->setVisible(true);
		m_ui->enterCodeTextLabel->setVisible(true);
		m_ui->createButton->setVisible(false);
		m_ui->joinButton->setVisible(false);
		m_ui->signOutButton->setVisible(false);
		m_ui->roomCode->setVisible(false);
		m_ui->codeLabel->setVisible(false);
	}
	if (state == ConvertStringToGameState("InGame"))
	{
		m_bigLogo->setVisible(false);
		m_ui->roundsChoice->setVisible(false);
		m_ui->roundsLabel->setVisible(false);
		m_ui->hintsChoice->setVisible(false);
		m_ui->hintsLabel->setVisible(false);
		m_ui->noPlayersChoice->setVisible(false);
		m_ui->noPlayersLabel->setVisible(false);
		m_ui->noWordsChoice->setVisible(false);
		m_ui->noWordsLabel->setVisible(false);
		m_ui->languageChoice->setVisible(false);
		m_ui->languageLabel->setVisible(false);
		m_ui->timeChoice->setVisible(false);
		m_ui->timeLabel->setVisible(false);
		m_ui->startButton->setVisible(false);
		m_ui->errorLabel->setVisible(false);
		m_ui->generatedCodeLabel->setVisible(false);
		m_ui->enterCodeTextLabel->setVisible(false);
		m_ui->notEnoughPlayers->setVisible(false);
		m_logo->setGeometry(5, 5, 100, 98);
		m_logo->setScaledContents(true);
		m_logo->setVisible(true);
		m_ui->timerLabel->setVisible(true);
		m_ui->clearButton->setVisible(true);
		m_ui->undoButton->setVisible(true);


	}

}

void MainWindow::Clear()
{
	if (!m_points.empty())
	{
		m_previousDrawings.push(m_points);
		auto response = cpr::Put(
			cpr::Url{ "http://localhost:13034/clearPoints" },
			cpr::Payload{
				{ "roomcode", m_roomcode}
			});
		m_points.clear();
		m_actionHistory.push(-1);
		update();
	}
}

void MainWindow::Undo()
{
	if (m_actionHistory.empty())
		return;
	else
		if (m_actionHistory.size() == 1)
		{
			m_points.clear();
			m_actionHistory.pop();
		}
		else
			if (m_actionHistory.top() == -1)
			{
				m_points = m_previousDrawings.top();
				m_previousDrawings.pop();
				m_actionHistory.pop();
			}
			else
			{
				int lastUndoPoint = m_actionHistory.top();
				m_actionHistory.pop();
				for (int index = lastUndoPoint; index > m_actionHistory.top(); index--)
					m_points.erase(index);
			}
	update();
}

void MainWindow::on_startButton_clicked()
{
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:13034/addChosenWords" },
		cpr::Payload{
			{ "roomcode", m_roomcode}
		});
	GetChosenWords();
	if (m_players.size() > 1)
	{
	if (m_ui->roundsChoice->currentText() != '-' && m_ui->hintsChoice->currentText() != '-' && m_ui->noPlayersChoice->currentText() != '-' &&
		m_ui->noWordsChoice->currentText() != '-' && m_ui->languageChoice->currentText() != '-' && m_ui->timeChoice->currentText() != '-')
	{
		m_gameState = ConvertStringToGameState("InGame");
		SetVisibilities(m_gameState);
		update();
		auto response = cpr::Put(
			cpr::Url{ "http://localhost:13034/modifyGameState" },
			cpr::Payload{
				{ "roomcode", m_roomcode},
				{ "gameState", ConvertGameStateToString(m_gameState)}
			});
	}
	else
	{
		m_ui->notEnoughPlayers->setVisible(false);
		m_ui->errorLabel->setVisible(true);
	}
	}
	else
		m_ui->notEnoughPlayers->setVisible(true);
}


void MainWindow::on_createButton_clicked()
{
	m_roomcode = GenerateCode();
	m_ui->generatedCodeLabel->setText(QString::fromStdString(m_roomcode));
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:13034/addGame" },
		cpr::Payload{
			{ "roomcode", m_roomcode},
			{ "user", m_username}
		}
	);
	m_host = true;
	m_ui->timeChoice->setEnabled(true);
	m_ui->languageChoice->setEnabled(true);
	m_ui->noPlayersChoice->setEnabled(true);
	m_ui->noWordsChoice->setEnabled(true);
	m_ui->hintsChoice->setEnabled(true);
	m_ui->roundsChoice->setEnabled(true);
	m_gameState = ConvertStringToGameState("MeetingRoom");
	SetVisibilities(m_gameState);
	GetPlayersInRoom();
	m_timer->start(100);
	update();
}


void MainWindow::on_joinButton_clicked()
{
	m_gameState = ConvertStringToGameState("EnterCode");
	SetVisibilities(m_gameState);
	update();
}


void MainWindow::on_clearButton_clicked()
{
	Clear();
}

void MainWindow::on_undoButton_clicked()
{
	Undo();
}

void MainWindow::on_loginButton_clicked()
{
	m_gameState = ConvertStringToGameState("LoginOrRegister");
	SetVisibilities(m_gameState);
	m_ui->loginText->setVisible(true);
	update();
	m_reg = false;
}

void MainWindow::on_registerButton_clicked()
{
	m_gameState = ConvertStringToGameState("LoginOrRegister");
	SetVisibilities(m_gameState);
	m_ui->registerText->setVisible(true);
	update();
	m_reg = true;
}

void MainWindow::on_signOutButton_clicked()
{
	m_gameState = ConvertStringToGameState("MainMenu");
	SetVisibilities(m_gameState);
	m_ui->username->clear();
	m_ui->password->clear();
	update();
}

void MainWindow::on_backButton_clicked()
{
	m_gameState = ConvertStringToGameState("MainMenu");
	SetVisibilities(m_gameState);
	m_ui->username->clear();
	m_ui->password->clear();
	update();
}

void MainWindow::on_password_textChanged()
{
	if (m_password.size() < m_ui->password->text().size())
		m_password = m_password + m_ui->password->text()[m_ui->password->text().size() - 1];
	else
		m_password.resize(m_ui->password->text().size());
	QString stars;
	for (int index = 0; index < m_password.size(); index++)
		stars = stars + '*';
	m_ui->password->setText(stars);
}

void MainWindow::CreateThread()
{
	QtConcurrent::run([this]() {
		if (m_gameState == ConvertStringToGameState("MeetingRoom"))
			GetPlayersInRoom();
		if (!m_host)
		{
			if (m_gameState == ConvertStringToGameState("MeetingRoom"))
			{
				GetSettings();
			}
			if (m_gameState == ConvertStringToGameState("InGame"))
				GetDrawing();
		}
		GetGuessesInChat();
		GetGameState();
		});
	SetVisibilities(m_gameState);
	update();
	/*if (!host)
	{
		QtConcurrent::run([this]() {GetSettings(); });
		QtConcurrent::run([this]() {GetGameState(); });
		setVisibilities(gameState);
		QtConcurrent::run([this]() {GetDrawing(); });
	}
	QtConcurrent::run([this]() {GetGuessesInChat(); });*/
}

void MainWindow::GetPlayersInRoom()
{
	std::string url = "http://localhost:13034/" + m_roomcode + "/players";
	auto response = cpr::Get(cpr::Url{ url });
	auto playerList = crow::json::load(response.text);
	if (m_players.size() != playerList["noPlayers"].i())
		for (int index = m_players.size(); index < playerList["noPlayers"].i(); index++)
		{
			std::string key = "user" + std::to_string(index);
			m_players.push_back(playerList[key].s());
		}
}

void MainWindow::GetSettings()
{
	std::string url = "http://localhost:13034/" + m_roomcode + "/settings";
	auto response = cpr::Get(cpr::Url{ url });
	auto roomSettings = crow::json::load(response.text);
	m_ui->timeChoice->setCurrentIndex(roomSettings["time"].i());
	m_ui->languageChoice->setCurrentIndex(roomSettings["language"].i());
	m_ui->noPlayersChoice->setCurrentIndex(roomSettings["maxNoPlayers"].i());
	m_ui->noWordsChoice->setCurrentIndex(roomSettings["noWords"].i());
	m_ui->hintsChoice->setCurrentIndex(roomSettings["hints"].i());
	m_ui->roundsChoice->setCurrentIndex(roomSettings["noRounds"].i());
}

void MainWindow::GetGuessesInChat()
{
	std::string url = "http://localhost:13034/" + m_roomcode + "/guesses";
	auto response = cpr::Get(cpr::Url{ url });
	auto guessList = crow::json::load(response.text);
	if (m_ui->guessList->count() != guessList["noGuesses"].i())
		for (int index = m_ui->guessList->count(); index < guessList["noGuesses"].i(); index++)
		{
			std::string key = "guess" + std::to_string(index);
			std::string text = guessList[key].s();
			ReplaceCharacters(text);
			m_ui->guessList->addItem(QString::fromStdString(text));
		}
}

void MainWindow::GetGameState()
{
	std::string url = "http://localhost:13034/" + m_roomcode + "/gameState";
	auto response = cpr::Get(cpr::Url{ url });
	auto gameStateJson = crow::json::load(response.text);
	if (gameStateJson["gameState"].s() != ConvertGameStateToString(m_gameState))
		m_gameState = ConvertStringToGameState(gameStateJson["gameState"].s());
	m_currentTime = gameStateJson["timer"].i();
	m_ui->timerLabel->setText(QString::number(m_currentTime));
}

void MainWindow::GetDrawing()
{
	std::string url = "http://localhost:13034/" + m_roomcode + "/points";
	auto response = cpr::Get(cpr::Url{ url });
	if (response.status_code == cpr::status::HTTP_OK)
	{
		auto pointsList = crow::json::load(response.text);
		if (m_points.size() != pointsList["noPoints"].i() && pointsList["noPoints"].i())
			for (int index = m_points.size(); index < pointsList["noPoints"].i(); index++)
			{
				std::string keyX = "x" + std::to_string(index);
				std::string keyY = "y" + std::to_string(index);
				std::string keyR = "red" + std::to_string(index);
				std::string keyG = "green" + std::to_string(index);
				std::string keyB = "blue" + std::to_string(index);
				std::string keyBrushSize = "brushSize" + std::to_string(index);
				std::string keyInWindow = "inWindow" + std::to_string(index);
				if (pointsList.has(keyX) && pointsList.has(keyY) && pointsList.has(keyR) && pointsList.has(keyG) &&
					pointsList.has(keyB) && pointsList.has(keyBrushSize) && pointsList.has(keyInWindow))
					m_points[index] = { static_cast<uint16_t>(pointsList[keyX].i()),static_cast<uint16_t>(pointsList[keyY].i()),
						static_cast<uint8_t>(pointsList[keyR].i()), static_cast<uint8_t>(pointsList[keyG].i()), static_cast<uint8_t>(pointsList[keyB].i()),
						static_cast<uint8_t>(pointsList[keyBrushSize].i()),pointsList[keyInWindow].b() };
			}
	}
}

void MainWindow::GetChosenWords()
{
	std::string url = "http://localhost:13034/" + m_roomcode + "/chosenWords";
	auto response = cpr::Get(cpr::Url{ url });
	auto WordList = crow::json::load(response.text);
	if (m_ui->guessList->count() != WordList["noWords"].i())
	{
		for (int index = m_words.size(); index < WordList["noWords"].i(); index++)
		{
			std::string key = "word" + std::to_string(index);
			std::string text = WordList[key].s();
			ReplaceCharacters(text);
			m_words.push_back(text);
		}
		for (int index = m_words.size(); index < m_words.size()+3; index++)
		{
			std::string key = "word" + std::to_string(index);
			std::string text = WordList[key].s();
			ReplaceCharacters(text);
			m_customWords.push_back(text);
		}
	}
}

void MainWindow::ModifySettings()
{
	if (m_host)
	{
		if (m_players.size() > m_ui->noPlayersChoice->currentIndex())
			m_ui->noPlayersChoice->setCurrentIndex(m_players.size() - 1);

		auto response = cpr::Put(
			cpr::Url{ "http://localhost:13034/modifySettings" },
			cpr::Payload{
				{ "roomcode", m_roomcode},
				{ "time", std::to_string(m_ui->timeChoice->currentIndex())},
				{ "language", std::to_string(m_ui->languageChoice->currentIndex())},
				{ "noPlayers", std::to_string(m_ui->noPlayersChoice->currentIndex())},
				{ "noWords", std::to_string(m_ui->noWordsChoice->currentIndex())},
				{ "hints", std::to_string(m_ui->hintsChoice->currentIndex())},
				{ "noRounds", std::to_string(m_ui->roundsChoice->currentIndex())}
			});
	}
}

void MainWindow::ReplaceCharacters(std::string& text)
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
	for (int i = 0; i < 6; i++)
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

void MainWindow::RunTimer()
{
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:13034/modifySettings" },
		cpr::Payload{
			{ "roomcode", m_roomcode}
		});
}

void MainWindow::on_timeChoice_currentTextChanged()
{
	ModifySettings();
}

void MainWindow::on_languageChoice_currentTextChanged()
{
	ModifySettings();
}

void MainWindow::on_noPlayersChoice_currentTextChanged()
{
	ModifySettings();
}

void MainWindow::on_noWordsChoice_currentTextChanged()
{
	ModifySettings();
}

void MainWindow::on_hintsChoice_currentTextChanged()
{
	ModifySettings();
}

void MainWindow::on_roundsChoice_currentTextChanged()
{
	ModifySettings();
}
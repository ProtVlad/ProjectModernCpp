module user;

using namespace http;

User::User(int id, std::string username, std::string password)
	:m_id{ id }, m_username{ username }, m_password{ password }
{
}

int User::GetId()const
{
	return m_id;
}

std::string http::User::GetUsername() const
{
	return m_username;
}

std::string http::User::GetPassword() const
{
	return m_password;
}

void User::SetId(int id)
{
	m_id = id;
}

void http::User::SetUsername(std::string username)
{
	m_username = username;
}

void http::User::SetPassword(std::string password)
{
	m_password = password;
}

export module user;
import <string>;

namespace http
{
	export class User
	{
	public:
		User() = default;
		User(int id, std::string username, std::string password);
		int GetId()const;
		std::string GetUsername()const;
		std::string GetPassword()const;

		void SetId(int id);
		void SetUsername(std::string username);
		void SetPassword(std::string password);

	private:

		int m_id;
		std::string m_username;
		std::string m_password;
	};
}
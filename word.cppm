export module word;

import <string>;

namespace http
{
	export class Word
	{
	public:
		Word() = default;
		Word(int id, const std::string& word, int price);

		int GetId() const;
		std::string GetWord()const;
		int GetPrice()const;

		void SetId(int id);
		void SetWord(const std::string& word);
		void SetPrice(int price);

	private:
		int m_id;
		std::string m_word;
		int m_price;
	};


}
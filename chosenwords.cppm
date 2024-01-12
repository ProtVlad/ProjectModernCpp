export module chosenwords;

import <string>;

namespace http
{
	export class ChosenWords
	{
	public:
		ChosenWords() = default;
		ChosenWords(int idWord, int numberWords);
		int GetId() const;
		int GetNumberWords() const;

		void SetId(int idWord);
		void SetNumberWords(int numberWords);

	private:

		int m_idWord;
		int m_numberWords;
	};
}
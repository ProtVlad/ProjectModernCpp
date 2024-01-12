module chosenwords;

using namespace http;

ChosenWords::ChosenWords(int idWord, int numberWords)
	:m_idWord{ idWord }, m_numberWords{ numberWords }
{
}

int ChosenWords::GetId() const
{
	return m_idWord;
}


int ChosenWords::GetNumberWords() const
{
	return m_numberWords;
}

void ChosenWords::SetId(int idWord)
{
	m_idWord = idWord;
}


void ChosenWords::SetNumberWords(int numberWords)
{
	m_numberWords = numberWords;
}

module word;

using namespace http;


int Word::GetId() const
{
	return m_id;
}

Word::Word(int id, const std::string& word, int price)
	:m_id{ id }, m_word{ word }, m_price{ price }
{
}

std::string Word::GetWord()const
{
	return m_word;
}

int Word::GetPrice()const
{
	return m_price;
}

void Word::SetId(int id)
{
	m_id = id;
}

void Word::SetWord(const std::string& word)
{
	m_word = word;
}

void Word::SetPrice(int price)
{
	m_price = price;
}
#include "GameDatabase.h"

using namespace http;

bool GameStorage::Initialize()
{
	m_db.sync_schema();
	auto initWordsCount = m_db.count<Word>();
	if (initWordsCount == 0)
		PopulateWordsStorage();

	auto wordsCount = m_db.count<Word>();
	return wordsCount != 0;
}

void GameStorage::PopulateWordsStorage()
{
	std::vector<Word> words{
		Word{-1,"trandafir",100},
		Word{-1,"artificii",150},
		Word{-1,"cuptor cu microunde",150},
		Word{-1,"clovn",150},
		Word{-1,"cuvant",50},
		Word{-1,"limba",50},
		Word{-1,"calculator",150},
		Word{-1,"Traian Basescu",50},
		Word{-1,"caseta",100},
		Word{-1,"buton",150},
		Word{-1,"grafic",150},
		Word{-1,"schema",50},
		Word{-1,"litera",50},
		Word{-1,"matematica",150},
		Word{-1,"profesor",150},
		Word{-1,"cana",150},
		Word{-1,"cafea",150},
		Word{-1,"Google",150},
		Word{-1,"ochelari",150},
		Word{-1,"oftalmolog",100},
		Word{-1,"dentist",150},
		Word{-1,"telefon fix",150},
		Word{-1,"sticla",100},
		Word{-1,"servetel",100},
		Word{-1,"raceala",100},
		Word{-1,"nervos",50},
		Word{-1,"bucle",100},
		Word{-1,"frizerie",150},
		Word{-1,"lumina",50},
		Word{-1,"arhitect",100},
		Word{-1,"programator",150},
		Word{-1,"sofer",150},
		Word{-1,"masina",150},
		Word{-1,"autobuz scolar",150},
		Word{-1,"camera video",100},
		Word{-1,"botez",100},
		Word{-1,"mireasa",150},
		Word{-1,"bebelus",150},
		Word{-1,"covrig",100},
		Word{-1,"creioane colorate",150},
		Word{-1,"tablou",100},
		Word{-1,"violet",50},
		Word{-1,"trandafiriu",50},
		Word{-1,"rebus",50},
		Word{-1,"Kaufland",150},
		Word{-1,"setari",50},
		Word{-1,"Victor Ponta",50},
		Word{-1,"rulouri",100},
		Word{-1,"Selly",50},
		Word{-1,"tigaie",150},
		Word{-1,"geometrie",100},
		Word{-1,"gnom",50},
		Word{-1,"avizier",100},
		Word{-1,"oglinda",150},
		Word{-1,"Aurora Boreala",100},
		Word{-1,"dolar",150},
		Word{-1,"cabana",100},
		Word{-1,"curcubeu",150},
		Word{-1,"veioza",150},
		Word{-1,"suc",150},
		Word{-1,"acnee",150},
		Word{-1,"aparat dentar",100},
		Word{-1,"miopie",50},
		Word{-1,"adolescent",50},
		Word{-1,"ghiozdan",150},
		Word{-1,"pusca",50},
		Word{-1,"palarie",150},
		Word{-1,"curea",150},
		Word{-1,"ghilotina",100},
		Word{-1,"ascensor",100},
		Word{-1,"convexitate",100},
		Word{-1,"descendent",50},
		Word{-1,"peste",150},
		Word{-1,"RAM",50},
		Word{-1,"instalator",100},
		Word{-1,"plata",50},
		Word{-1,"ciob",50},
		Word{-1,"trabuc",100},
		Word{-1,"uscat",50},
		Word{-1,"umed",50},
		Word{-1,"mar",150},
		Word{-1,"diferenta",100},
		Word{-1,"mare",100},
		Word{-1,"mic",50},
		Word{-1,"fantoma",150},
		Word{-1,"pamant",50},
		Word{-1,"univers",150},
		Word{-1,"mormant",150},
		Word{-1,"Statuia Libertatii",100},
		Word{-1,"credinta",100},
		Word{-1,"idee",100},
		Word{-1,"ventilator",150},
		Word{-1,"feon",100},
		Word{-1,"Facebook",150},
		Word{-1,"portiera",100},
		Word{-1,"motor",100},
		Word{-1,"ghidon",100},
		Word{-1,"parcare",150},
		Word{-1,"gara",100},
		Word{-1,"carte",150},
		Word{ -1,"locuinta",50 },
		Word{ -1,"spiridus",50 },
		Word{ -1,"incarcator",100 },
		Word{ -1,"miraj",50 },
		Word{ -1,"umbra",100 },
		Word{ -1,"pisica",100 },
		Word{ -1,"ghinion",50 },
		Word{ -1,"ecran",100 },
		Word{ -1,"randunica",50 },
		Word{ -1,"Instagram",150 },
		Word{ -1,"vointa",50 },
		Word{ -1,"ciocolata",150 },
		Word{ -1,"budinca",150 },
		Word{ -1,"zi de nastere",150 },
		Word{ -1,"aniversare",50 },
		Word{ -1,"ghirlanda",150 },
		Word{ -1,"familie",150 },
		Word{ -1,"Craciun",150 },
		Word{ -1,"sarmale",150 },
		Word{ -1,"Franta",150 },
		Word{ -1,"napolitane",100 },
		Word{ -1,"Klaus Iohannis",50 },
		Word{ -1,"nume de familie",100 },
		Word{ -1,"carte de identitate",150 },
		Word{ -1,"CNP",100 },
		Word{ -1,"veteran",50 },
		Word{ -1,"tanc",100 },
		Word{ -1,"castron",100 },
		Word{ -1,"strachina",50 },
		Word{ -1,"bunic",100 },
		Word{ -1,"frati",100 },
		Word{ -1,"gemeni",100 },
		Word{ -1,"rochie",150 },
		Word{ -1,"papion",150 },
		Word{ -1,"brunet",150 },
		Word{ -1,"gene false",100 },
		Word{ -1,"locatie",50 },
		Word{ -1,"politie",100 },
		Word{ -1,"IKEA",100 },
		Word{ -1,"chifle",150 },
		Word{ -1,"metrou",100 },
		Word{ -1,"Carrefour",150 },
		Word{ -1,"Auchan",100 },
		Word{ -1,"mango",100 },
		Word{ -1,"papaya",100 },
		Word{ -1,"parfum",150 },
		Word{ -1,"mireasma",50 },
		Word{ -1,"teapa",50 },
		Word{ -1,"Vlad Tepes",100 },
		Word{ -1,"vampir",100 },
		Word{ -1,"rotund",50 },
		Word{ -1,"scrisoare",100 },
		Word{ -1,"cerc",100 },
		Word{ -1,"verde",50 },
		Word{ -1,"masca",100 },
		Word{ -1,"bal mascat",50 },
		Word{ -1,"plita",100 },
		Word{ -1,"bucatar",150 },
		Word{ -1,"salata",150 },
		Word{ -1,"viroza",50 },
		Word{ -1,"coacaze",100 },
		Word{ -1,"magnolie",50 },
		Word{ -1,"orhidee",50 },
		Word{ -1,"Ziua Mamei",100 },
		Word{ -1,"copil",150 },
		Word{ -1,"stralucitor",100 },
		Word{ -1,"argint",100 },
		Word{ -1,"casatorie",150 },
		Word{ -1,"teava",50 },
		Word{ -1,"interfon",150 },
		Word{ -1,"sonerie",100 },
		Word{ -1,"bomboane",150 },
		Word{ -1,"ambalaj",150 },
		Word{ -1,"cadou",150 },
		Word{ -1,"Mos Craciun",150 },
		Word{ -1,"priza",150 },
		Word{ -1,"mici cu mustar",150 },
		Word{ -1,"degustator de vin",100 },
		Word{ -1,"scut",150 },
		Word{ -1,"craniu",150 },
		Word{ -1,"primarie",150 },
		Word{ -1,"vacanta",100 },
		Word{ -1,"Maldive",50 },
		Word{ -1,"palmier",100 },
		Word{ -1,"ocean",100 },
		Word{ -1,"continent",100 },
		Word{ -1,"America",150 },
		Word{ -1,"pizza",150 },
		Word{ -1,"tomberon",150 },
		Word{ -1,"marmelada",100 },
		Word{ -1,"mic dejun",150 },
		Word{ -1,"orez cu lapte",100 },
		Word{ -1,"fructiera",100 },
		Word{ -1,"scortisoara",50 },
		Word{ -1,"piper",150 },
		Word{ -1,"mucenici",100 },
		Word{ -1,"pasta de tomate",100 },
		Word{ -1,"sos de rosii",150 },
		Word{ -1,"sah",150 },
		Word{ -1,"regina",150 },
		Word{ -1,"cal",100 },
		Word{ -1,"Arc de Triumf",100 },
		Word{ -1,"Poarta Sarutului",50 },
		Word{ -1,"Coloana Infinitului",50 },
		Word{ -1,"Cleopatra",50 },
		Word{ -1,"calcai",50 },
		Word{ -1,"Medusa",100 },
		Word{ -1,"meduza",150 },
		Word{ -1,"caracatita",100 },
		Word{ -1,"balena",100 },
		Word{ -1,"pestera",100 },
		Word{ -1,"pustnic",50 },
		Word{ -1,"biliard",150 },
		Word{ -1,"bula",100 },
		Word{ -1,"iarba",150 },
		Word{ -1,"gazon",100 },
		Word{ -1,"sapa",150 },
		Word{ -1,"lopata",150 },
		Word{ -1,"masina de tuns iarba",50 },
		Word{ -1,"Mihai Eminescu",50 },
		Word{ -1,"Veronica Micle",50 },
		Word{ -1,"Amintiri din copilarie",50 },
		Word{ -1,"vanatoare",50 },
		Word{ -1,"prada",50 },
		Word{ -1,"regat",100 },
		Word{ -1,"imparat",150 },
		Word{ -1,"Harap Alb",50 },
		Word{ -1,"unghii",150 },
		Word{ -1,"buze",150 },
		Word{ -1,"deget de la picior",100 },
		Word{ -1,"deget inelar",100 },
		Word{ -1,"deget mare",100 },
		Word{ -1,"deget mic",100 },
		Word{ -1,"tort",150 },
		Word{ -1,"frisca",150 },
		Word{ -1,"Starbucks",150 },
		Word{ -1,"KFC",100 },
		Word{ -1,"jandarmerie",100 },
		Word{ -1,"masina de pompieri",150 },
		Word{ -1,"urgente",100 },
		Word{ -1,"cinema",150 },
		Word{ -1,"erou",50 },
		Word{ -1,"vapor",150 },
		Word{ -1,"pirat",150 },
		Word{ -1,"ciclop",150 },
		Word{ -1,"ciclon",50 },
		Word{ -1,"zeu",100 },
		Word{ -1,"tunet",50 },
		Word{ -1,"fulger",150 },
		Word{ -1,"furtuna",50 },
		Word{ -1,"apocalipsa",50 },
		Word{ -1,"caleasca",50 },
		Word{ -1,"cataclism",50 },
		Word{ -1,"ciclism",100 },
		Word{ -1,"Sud",150 },
		Word{ -1,"Nord",150 },
		Word{ -1,"Est",150 },
		Word{ -1,"Vest",150 },
		Word{ -1,"busola",150 },
		Word{ -1,"cada",150 },
		Word{ -1,"draperie",150 },
		Word{ -1,"covor",150 },
		Word{ -1,"lume",100 },
		Word{ -1,"biserica",150 },
		Word{ -1,"mistic",50 },
		Word{ -1,"ceata",100 },
		Word{ -1,"padure",150 },
		Word{ -1,"luminis",50 },
		Word{ -1,"menta",100 },
		Word{ -1,"musetel",50 },
		Word{ -1,"gheata",150 },
		Word{ -1,"patinoar",150 },
		Word{ -1,"conopida",100 },
		Word{ -1,"papadie",150 },
		Word{ -1,"vreme",100 },
		Word{ -1,"zana",100 },
		Word{ -1,"dinte de lapte",50 },
		Word{ -1,"reparatie",50 },
		Word{ -1,"judecator",100 },
		Word{ -1,"film",100 },
		Word{ -1,"gustare",100 },
		Word{ -1,"dovleac",150 },
		Word{ -1,"labirint",150 },
		Word{ -1,"stop",150 },
		Word{ -1,"iesire",150 },
		Word{ -1,"viziune",50 },
		Word{ -1,"vraja",50 },
		Word{ -1,"mixer",150 },
		Word{ -1,"espressor",50 },
		Word{ -1,"nota de trecere",50 },
		Word{ -1,"sunca",50 },
		Word{ -1,"salam",100 },
		Word{ -1,"branza",100 },
		Word{ -1,"rosii",150 },
		Word{ -1,"castraveti",150 },
		Word{ -1,"iaurt",100 },
		Word{ -1,"luminite",100 },
		Word{ -1,"calorifer",50 },
		Word{ -1,"zaruri",150 },
		Word{ -1,"joc de noroc",100 },
		Word{ -1,"pantaloni",150 },
		Word{ -1,"bijuterii",150 },
		Word{ -1,"clanta",150 },
		Word{ -1,"Stefan cel Mare",50 },
		Word{ -1,"magie",50 },
		Word{ -1,"tricou",150 },
		Word{ -1,"camera",100 },
		Word{ -1,"curte",150 },
		Word{ -1,"asfalt",100 },
		Word{ -1,"trecere de pietoni",150 },
		Word{ -1,"ceainic",100 },
		Word{ -1,"lampa lui Aladin",100 },
		Word{ -1,"caine dalmatian",100 },
		Word{ -1,"Jack si vrejul de fasole",50 },
		Word{ -1,"lanterna",100 },
		Word{ -1,"test",150 },
		Word{ -1,"liceu",100 },
		Word{ -1,"chimie",100 },
		Word{ -1,"reactie chimica",100 },
		Word{ -1,"mazare",150 },
		Word{ -1,"piure",150 },
		Word{ -1,"angajat",100 },
		Word{ -1,"telecomanda",150 },
		Word{ -1,"helesteu",50 },
		Word{ -1,"rama",150 },
		Word{ -1,"zahar",150 },
		Word{ -1,"sosea",150 },
		Word{ -1,"infrastructura",50 },
		Word{ -1,"alergator",100 },
		Word{ -1,"baterie",100 },
		Word{ -1,"apel telefonic",50 },
		Word{ -1,"spital",100 },
		Word{ -1,"patiserie",100 },
		Word{ -1,"cofetar",50 },
		Word{ -1,"semn",50 },
		Word{ -1,"multime",50 },
		Word{ -1,"gluga",150 },
		Word{ -1,"zambet",150 },
		Word{ -1,"pasaport",100 },
		Word{ -1,"aeroport",100 },
		Word{ -1,"elicopter",150 },
		Word{ -1,"scaun",150 },
		Word{ -1,"vanilie",50 },
		Word{ -1,"abur",100 },
		Word{ -1,"cutie",150 },
		Word{ -1,"pachet",100 },
		Word{ -1,"curier",150 },
		Word{ -1,"distribuire",100 },
		Word{ -1,"frana",100 },
		Word{ -1,"porc",150 },
		Word{ -1,"urs panda",150 },
		Word{ -1,"gaina",50 },
		Word{ -1,"rana",100 },
		Word{ -1,"accident",100 },
		Word{ -1,"laptop",150 },
		Word{ -1,"stele",150 },
		Word{ -1,"intuneric",50 },
		Word{ -1,"noapte",150 },
		Word{ -1,"rasarit",150 },
		Word{ -1,"apus",150 },
		Word{ -1,"nori",150 },
		Word{ -1,"natura",100 },
		Word{ -1,"cartela de acces",50 },
		Word{ -1,"munte",150 },
		Word{ -1,"deal",100 },
		Word{ -1,"campie",100 },
		Word{ -1,"floarea soarelui",150 },
		Word{ -1,"balama",50 },
		Word{ -1,"usa",150 },
		Word{ -1,"diavol",150 },
		Word{ -1,"flacari",100 },
		Word{ -1,"rai",50 },
		Word{ -1,"durere",50 },
		Word{ -1,"bani",150 },
		Word{ -1,"card",100 },
		Word{ -1,"bogat",100 },
		Word{ -1,"sarac",100 },
		Word{ -1,"cod de bare",100 },
		Word{ -1,"patrat",150 },
		Word{ -1,"cateta",100 },
		Word{ -1,"eticheta",150 },
		Word{ -1,"haine",150 },
		Word{ -1,"dulap",150 },
		Word{ -1,"alegere",50 },
		Word{ -1,"maini",150 },
		Word{ -1,"cot",150 },
		Word{ -1,"cort",100 },
		Word{ -1,"foc de tabara",150 },
		Word{ -1,"ciocolata calda",100 },
		Word{ -1,"pictura",100 },
		Word{ -1,"instructiuni",50 },
		Word{ -1,"mobilier",100 },
		Word{ -1,"pilota",100 },
		Word{ -1,"poseta",150 },
		Word{ -1,"grau",50 },
		Word{ -1,"orez",100 },
		Word{ -1,"suflet",50 },
		Word{ -1,"inima",150 },
		Word{ -1,"nas",150 },
		Word{ -1,"ureche",150 },
		Word{ -1,"termos",100 },
		Word{ -1,"termometru",150 },
		Word{ -1,"stranut",50 },
		Word{ -1,"cirese",150 },
		Word{ -1,"portocale",150 },
		Word{ -1,"piele",50 },
		Word{ -1,"inel",150 },
		Word{ -1,"observator",50 },
		Word{ -1,"tastatura",150 },
		Word{ -1,"punct",150 },
		Word{ -1,"semnul exclamarii",150 },
		Word{ -1,"tava",100 },
		Word{ -1,"piscina",150 },
		Word{ -1,"cutit",150 },
		Word{ -1,"furculita",150 },
		Word{ -1,"lingura",150 },
		Word{ -1,"lingura de lemn",100 },
		Word{ -1,"auriu",50 },
		Word{ -1,"marmura",50 },
		Word{ -1,"sticla",150 },
		Word{ -1,"jeleu",50 },
		Word{ -1,"vizita",50 },
		Word{ -1,"cuier",100 },
		Word{ -1,"debara",50 },
		Word{ -1,"raft",100 },
		Word{ -1,"tigru",100 },
		Word{ -1,"centrala",50 },
		Word{ -1,"trening",100 },
		Word{ -1,"berbec",50 },
		Word{ -1,"rac",50 },
		Word{ -1,"fecioara",50 },
		Word{ -1,"scorpion",50 },
		Word{ -1,"varsator",50 },
		Word{ -1,"primavara",100 },
		Word{ -1,"toamna",100 },
		Word{ -1,"iarna",100 },
		Word{ -1,"vara",100 },
		Word{ -1,"trafalet",50 },
		Word{ -1,"pensula",150 },
		Word{ -1,"acuarele",150 },
		Word{ -1,"crocodil",50 },
		Word{ -1,"broasca testoasa",100 },
		Word{ -1,"horoscop",50 },
		Word{ -1,"taxi",150 },
		Word{ -1,"alarma",150 },
		Word{ -1,"parchet",50 },
		Word{ -1,"sobolan",50 },
		Word{ -1,"Cenusareasa",50 },
		Word{ -1,"lup",100 },
		Word{ -1,"soparla",100 },
		Word{ -1,"surub",100 },
		Word{ -1,"ciocan",150 },
		Word{ -1,"dragon",50 },
		Word{ -1,"sarpe",150 },
		Word{ -1,"maimuta",100 },
		Word{ -1,"mesaj",100 },
		Word{ -1,"aplicatie",150 },
		Word{ -1,"calendar",150 },
		Word{ -1,"muzica",100 },
		Word{ -1,"farfurie",150 },
		Word{ -1,"taraba",100 },
		Word{ -1,"intrare",100 },
		Word{ -1,"lift",50 },
		Word{ -1,"zid",100 },
		Word{ -1,"Samsung",100 },
		Word{ -1,"sultan",50 },
		Word{ -1,"baclava",50 },
		Word{ -1,"ulei de masline",100 },
		Word{ -1,"picnic",150 },
		Word{ -1,"cina",100 },
		Word{ -1,"roata",150 },
		Word{ -1,"moschee",50 },
		Word{ -1,"piatra",100 },
		Word{ -1,"harpa",100 },
		Word{ -1,"sirena",150 },
		Word{ -1,"vulpe",100 },
		Word{ -1,"ochi de aragaz",100 },
		Word{ -1,"tortura",50 },
		Word{ -1,"securitate",100 },
		Word{ -1,"hartie igienica",100 },
		Word{ -1,"gel de dus",100 },
		Word{ -1,"ambulanta",150 },
		Word{ -1,"geam",150 },
		Word{ -1,"pahar",150 },
		Word{ -1,"bananier",150 },
		Word{ -1,"florarie",150 },
		Word{ -1,"ospatar",150 },
		Word{ -1,"corect",100 },
		Word{ -1,"fereastra",150 },
		Word{ -1,"bibelou",50 },
		Word{ -1,"mileu",50 },
		Word{ -1,"sprancene",150 },
		Word{ -1,"breton",150 },
		Word{ -1,"Barbie",150 },
		Word{ -1,"baiat",150 },
		Word{ -1,"fata",150 },
		Word{ -1,"desert",150 },
		Word{ -1,"mustata",150 },
		Word{ -1,"caserola",100 },
		Word{ -1,"drujba",150 },
		Word{ -1,"Borsec",50 },
		Word{ -1,"Dorna",50 },
		Word{ -1,"cleste de par",100 },
		Word{ -1,"elastic",100 },
		Word{ -1,"adeziv",50 },
		Word{ -1,"raza de soare",50 },
		Word{ -1,"bloc",150 },
		Word{ -1,"apartament",100 },
		Word{ -1,"complet",50 },
		Word{ -1,"aparat de ras",50 },
		Word{ -1,"metal",50 },
		Word{ -1,"plic",100 },
		Word{ -1,"posta",100 },
		Word{ -1,"timbru",150 },
		Word{ -1,"vedere",50 },
		Word{ -1,"tufa",100 },
		Word{ -1,"breloc",150 },
		Word{ -1,"cercei",150 },
		Word{ -1,"umeras",150 },
		Word{ -1,"optiune",100 },
		Word{ -1,"esofag",50 },
		Word{ -1,"durere de gat",50 },
		Word{ -1,"costum de baie",150 },
		Word{ -1,"mamaliga",150 },
		Word{ -1,"sorici",50 },
		Word{ -1,"ascutitoare",100 },
		Word{ -1,"penar",150 },
		Word{ -1,"iepure",50 },
		Word{ -1,"vizor",50 },
		Word{ -1,"zodiac",50 },
		Word{ -1,"musca",50 },
		Word{ -1,"loz",50 },
		Word{ -1,"loterie",50 },
		Word{ -1,"biscuiti",100 },
		Word{ -1,"vinil",50 },
		Word{ -1,"prezentator",100 },
		Word{ -1,"radio",100 },
		Word{ -1,"pitic de gradina",100 },
		Word{ -1,"Alba ca Zapada",100 },
		Word{ -1,"groapa",50 },
		Word{ -1,"groaza",50 },
		Word{ -1,"vis",50 },
		Word{ -1,"pistol",100 },
		Word{ -1,"rezultat",50 },
		Word{ -1,"Wi-Fi",150 },
		Word{ -1,"ceas",150 },
		Word{ -1,"Iepurasul de Paste",100 },
		Word{ -1,"divinitate",50 },
		Word{ -1,"salopeta",150 },
		Word{ -1,"pantofi cu toc",100 },
		Word{ -1,"lac de unghii",100 },
		Word{ -1,"paleta de machiaj",100 },
		Word{ -1,"cui",150 },
		Word{ -1,"lemn",100 },
		Word{ -1,"brad",150 },
		Word{ -1,"lumanare",150 },
		Word{ -1,"diez",150 },
		Word{ -1,"liniste",50 },
		Word{ -1,"palton",100 },
		Word{ -1,"parasuta",150 },
		Word{ -1,"sedinta foto",150 },
		Word{ -1,"apa minerala",150 },
		Word{ -1,"izvor",150 },
		Word{ -1,"proiector",100 },
		Word{ -1,"papanasi",100 },
		Word{ -1,"maner",150 },
		Word{ -1,"canapea",100 },
		Word{ -1,"sufragerie",50 },
		Word{ -1,"recipient",100 },
		Word{ -1,"cozonac",100 },
		Word{ -1,"incaltaminte",150 },
		Word{ -1,"Andreea Esca",100 },
		Word{ -1,"fotosinteza",50 },
		Word{ -1,"biologie",50 },
		Word{ -1,"arbore genealogic",100 },
		Word{ -1,"girafa",150 },
		Word{ -1,"elefant",100 },
		Word{ -1,"savana",50 },
		Word{ -1,"slab",100 },
		Word{ -1,"supraponderal",50 },
		Word{ -1,"cantar",150 },
		Word{ -1,"bol",100 },
		Word{ -1,"zapada",150 },
		Word{ -1,"bulgare de zapada",100 },
		Word{ -1,"sanie",100 },
		Word{ -1,"floare de lotus",100 },
		Word{ -1,"costum",150 },
		Word{ -1,"cosmos",50 },
		Word{ -1,"cavaler",100 },
		Word{ -1,"spada",50 },
		Word{ -1,"desen animat",100 },
		Word{ -1,"cartof",100 },
		Word{ -1,"ceapa",150 },
		Word{ -1,"usturoi",150 },
		Word{ -1,"saptamana",150 },
		Word{ -1,"smantana",150 }
	};
	m_db.insert_range(words.begin(), words.end());
}

std::vector<Word> GameStorage::GetWords()
{
	return m_db.get_all<Word>();
}

std::vector<User> GameStorage::GetUsers()
{
	return m_db.get_all<User>();
}

std::vector<Game> GameStorage::GetGames()
{
	return m_games;
}

//std::vector<std::tuple<std::string, int, int>> GameStorage::GetChosenWords()
//{
//	return m_db.select(
//		sql::columns(&Word::GetWord, &Word::GetPrice, &ChosenWords::GetNumberWords),
//		sql::inner_join<ChosenWords>(sql::on(sql::c(&Word::GetId) == &ChosenWords::GetId))
//	);
//}
//
void GameStorage::AddUserToDatabase(std::string& username, std::string& password)
{
	User user;
	user.SetUsername(username);
	user.SetPassword(password);
	m_db.insert(user);
}

//void GameStorage::AddWordToChosenWords(int id, int numberWords)
//{
//	ChosenWords w;
//	w.SetId(id);
//	w.SetNumberWords(numberWords);
//
//	m_db.insert(w);
//}
//http::AddToChosenWordsHandler::AddToChosenWordsHandler(GameStorage& storage)
//	: m_db{ storage }
//{
//}

//
void http::GameStorage::AddGame(std::string& roomcode, std::string& host)
{
	Settings settings(0, 0, 0, 0, 0, 0);
	Game game(roomcode, 0, 0, settings, "MeetingRoom");
	game.AddPlayer(host);
	m_games.push_back(game);
}

void http::GameStorage::AddPlayerInRoom(std::string& roomcode, std::string& user)
{
	for (int index = 0; index < m_games.size(); index++)
		if (m_games[index].GetRoomcode() == roomcode)
		{
			m_games[index].AddPlayer(user);
			break;
		}
}

void http::GameStorage::ModifySettings(std::string& roomcode, uint16_t time, uint16_t language, uint16_t noPlayers, uint16_t noWords, uint16_t hints, uint16_t rounds)
{
	for (int index = 0; index < m_games.size(); index++)
		if (m_games[index].GetRoomcode() == roomcode)
		{
			Settings settings(time, language, noPlayers, noWords, hints, rounds);
			m_games[index].SetSettings(settings);
			break;
		}
}

void http::GameStorage::AddGuess(std::string& roomcode, std::string& guess)
{
	for (int index = 0; index < m_games.size(); index++)
		if (m_games[index].GetRoomcode() == roomcode)
		{
			m_games[index].AddGuess(guess);
			break;
		}
}

void http::GameStorage::ModifyGameState(std::string& roomcode, std::string& gameState)
{
	for (int index = 0; index < m_games.size(); index++)
		if (m_games[index].GetRoomcode() == roomcode)
		{
			m_games[index].SetGameState(gameState);
			break;
		}
}

void http::GameStorage::AddPointInDrawing(std::string& roomcode, uint16_t x, uint16_t y, uint16_t r, uint16_t g, uint16_t b, uint8_t brushSize, bool inWindow)
{
	for (int index = 0; index < m_games.size(); index++)
		if (m_games[index].GetRoomcode() == roomcode)
		{
			m_games[index].AddPoint(Points{ x, y, r, g, b, brushSize, inWindow });
			break;
		}
}

void GameStorage::AddWordInChosenWords(std::string& roomcode)
{
	uint16_t max = m_db.count<Word>();
	uint16_t min = 1;

	for (int index = 0; index < m_games.size(); index++)
		if (m_games[index].GetRoomcode() == roomcode)
		{
			int nr = m_games[index].GetSettings().GetNumberWords();
			for (uint16_t cuvantAdaugat = 0; cuvantAdaugat < nr; cuvantAdaugat++)
			{
				uint16_t p = GenerateRandomNumber(min, max);
				/*int p1 = std::static_cast<int>(p);*/
				std::string cuv = GameStorage::GetWords()[p].GetWord();
				m_games[index].AddChosenWord(cuv);
			}
			break;
		}
}

uint16_t GameStorage::GenerateRandomNumber(uint16_t min, uint16_t max)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<uint16_t> distribution(min, max);
	int randomValue = distribution(generator);
	return randomValue;
}

AddUserHandler::AddUserHandler(GameStorage& storage)
	: m_db{ storage }
{
}

AddGameHandler::AddGameHandler(GameStorage& storage)
	: m_games{ storage }
{
}

AddPlayerHandler::AddPlayerHandler(GameStorage& storage)
	: m_games{ storage }
{
}

ModifySettingsHandler::ModifySettingsHandler(GameStorage& storage)
	: m_games{ storage }
{
}

AddGuessHandler::AddGuessHandler(GameStorage& storage)
	: m_games{ storage }
{
}

ModifyGameStateHandler::ModifyGameStateHandler(GameStorage& storage)
	: m_games{ storage }
{
}

AddPointsHandler::AddPointsHandler(GameStorage& storage)
	: m_games{ storage }
{
}

http::AddChosenWordsHandler::AddChosenWordsHandler(GameStorage& storage)
	:m_data{ storage }
{
}

crow::response AddUserHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");
	auto passwordIter = bodyArgs.find("password");
	if (usernameIter != end && passwordIter != end)
		m_db.AddUserToDatabase(usernameIter->second, passwordIter->second);
	return crow::response(201);
}

crow::response AddGameHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	auto hostIter = bodyArgs.find("user");
	if (roomcodeIter != end && hostIter != end)
		m_games.AddGame(roomcodeIter->second, hostIter->second);
	return crow::response(201);
}

crow::response AddPlayerHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	auto userIter = bodyArgs.find("user");
	if (roomcodeIter != end && userIter != end)
		m_games.AddPlayerInRoom(roomcodeIter->second, userIter->second);
	return crow::response(201);
}

crow::response ModifySettingsHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	auto timeIter = bodyArgs.find("time");
	auto languageIter = bodyArgs.find("language");
	auto noPlayersIter = bodyArgs.find("noPlayers");
	auto noWordsIter = bodyArgs.find("noWords");
	auto hintsIter = bodyArgs.find("hints");
	auto noRoundsIter = bodyArgs.find("noRounds");
	if (roomcodeIter != end && timeIter != end && languageIter != end && noPlayersIter != end
		&& noWordsIter != end && hintsIter != end && noRoundsIter != end)
		m_games.ModifySettings(roomcodeIter->second, std::stoi(timeIter->second), std::stoi(languageIter->second),
			std::stoi(noPlayersIter->second), std::stoi(noWordsIter->second), std::stoi(hintsIter->second),
			std::stoi(noRoundsIter->second));
	return crow::response(201);
}

crow::response AddGuessHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	auto guessIter = bodyArgs.find("guess");
	if (roomcodeIter != end && guessIter != end)
		m_games.AddGuess(roomcodeIter->second, guessIter->second);
	return crow::response(201);
}

crow::response ModifyGameStateHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	auto gameStateIter = bodyArgs.find("gameState");
	if (roomcodeIter != end && gameStateIter != end)
		m_games.ModifyGameState(roomcodeIter->second, gameStateIter->second);
	return crow::response(201);
}

crow::response AddPointsHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	auto xIter = bodyArgs.find("xCoord");
	auto yIter = bodyArgs.find("yCoord");
	auto RIter = bodyArgs.find("rColor");
	auto GIter = bodyArgs.find("gColor");
	auto BIter = bodyArgs.find("bColor");
	auto brushSizeIter = bodyArgs.find("brushSize");
	auto inWindowIter = bodyArgs.find("inWindow");
	if (roomcodeIter != end && xIter != end && yIter != end && RIter != end && GIter != end &&
		BIter != end && brushSizeIter != end && inWindowIter != end)
		m_games.AddPointInDrawing(roomcodeIter->second, std::stoi(xIter->second), std::stoi(yIter->second),
			std::stoi(RIter->second), std::stoi(GIter->second), std::stoi(BIter->second), std::stoi(brushSizeIter->second),
			static_cast<bool>(std::stoi(inWindowIter->second)));
	return crow::response(201);
}

crow::response AddChosenWordsHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto roomcodeIter = bodyArgs.find("roomcode");
	if (roomcodeIter != end)
		m_data.AddWordInChosenWords(roomcodeIter->second);

	return crow::response(201);
}



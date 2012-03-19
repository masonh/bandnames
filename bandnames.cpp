/* 
 * outputs a random band name based on lists from Rock Band
 * I found the lists online somewhere. don't expect them to be completely accurate
 * i based my code on a previous program i wrote, bofh
 * both are available on github at http://github.com/masonh
 * enjoy!
 */

/*
 * BUGS:
 *
 * It can only return one unique band name per second because rand() is
 * seeded with time(), which returns seconds. I don't think this will be an
 * issue for most people, though.
 *
 * Requires C++0x / C++11 compiler.
 *
 * Do not use data files with \r\n for line breaks. only use \n
 */


#include <cstdio>
#ifdef WIN32
#include <conio.h>
#endif
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

bool dump=false;	// dump internal lists to data files
bool bstat=false;	// enable data files by default
bool nstat=false;	// disable internal lists? default (false) enable them

#define LIST1 "list1.dat"
#define LIST2 "list2.dat"


struct wordlist
{
	vector<string> word;
};

int stat(string nothing, wordlist &st)
{
	if(nothing == LIST1) // list 1
	{
		st.word= {
"Aardvark",
"Apocalypse",
"Bad",
"Bikini",
"Boston",
"Breadstick",
"Broken",
"Bucket and",
"Camden",
"Captain",
"Cephalopod",
"Chekhovs",
"Coastal",
"Covers",
"Death",
"Death-Pit",
"Delicious",
"Delta",
"Digital",
"Donkey",
"Dr.",
"Eccentric",
"Electric",
"Estimated",
"Faceless",
"Facial",
"Fallen",
"Father",
"Fever Dream",
"Fiendish",
"Five Alarm",
"Foot",
"Four Alarm",
"Fretless",
"Galileos",
"Gin and",
"Goony",
"Grizzly Bear",
"Grum",
"Guest",
"Hardlaser",
"Harmonicus",
"Hedgehog",
"Hopopotamus",
"Horse",
"Hound",
"Jefferson",
"Kafkas",
"Killa",
"Killasaurus",
"Languishing",
"Loading",
"Lord",
"Lunchbox of",
"Luv",
"Mantiss",
"Masterful",
"Men With",
"Metallic",
"Metric",
"Mikey and",
"Miss",
"Monkey",
"Moustache",
"Mr.",
"Orange",
"Original",
"Orlando",
"Penguin",
"Penny",
"Perspiring",
"Pixelface",
"Prague",
"Raspberry",
"Razorblade",
"Real",
"Salt Horse",
"Sir",
"Snuggle",
"Stir-Fry",
"Supercilious",
"Taming",
"Taxonomic",
"Texas",
"The",
"The Babbling",
"The Cabinet",
"The Damp",
"The Doo-Wah",
"The Empty",
"The Grunting",
"The Holy",
"The Howler",
"The Hyperbolic",
"The Inverted",
"The Low",
"The Navel",
"The Nose",
"The Odious",
"The Shaven",
"The Stylish",
"The Totality",
"The Whining",
"Three Alarm",
"Toasty",
"Tog",
"Try for",
"Ultra",
"Unicorn",
"Vapor",
"Waxy",
"Weekend of",
"Whiteboard",
"Wooly",
"Wynnum"};
	}
	else if(nothing == LIST2) // list 2
	{
		st.word={
"Agony",
"Amplitude",
"and the Hex",
"Apples",
"Arcade",
"Atrophy",
"Babes",
"Baggage",
"Baptistes",
"Barbers",
"Bees",
"Blood",
"Bonnets",
"Brain Stem",
"Bubbles",
"Byron",
"Cannon",
"Captains",
"Cart",
"Charismatics",
"Chow",
"Circus",
"Coma",
"Commas",
"Contacts",
"Cordial",
"Culture",
"Cybersquad",
"Death",
"Diddies",
"Diet",
"Disaster",
"Dog Party",
"Dornholes",
"Dropbear",
"Ether",
"Flavors",
"Fraternity",
"FreQs",
"Friday",
"Friends",
"Frijoles",
"Furnace",
"Gerbil",
"Glory Days",
"Goblins",
"Goons",
"Gun",
"Harmonicus",
"Hat",
"Heroes",
"Hill",
"Hipopotamus",
"Horse",
"Howler",
"Icarus",
"in a Day",
"Index",
"Kohlers",
"Legends",
"Lemonade",
"Lincoln",
"Lock",
"Machine",
"Mantiss",
"Mechanotherapy",
"Mistress",
"Monday",
"Monkeys",
"Monotremes",
"Moustache",
"Not Included",
"Notre Dame",
"of Nouns",
"Oranges",
"Pallor",
"Pants",
"Party",
"Pastries",
"Phase",
"Philosophers",
"Pixelface",
"Prophet",
"Psychos",
"Pump",
"Punkaceratops",
"Puppy",
"Ramp",
"Razor",
"Robots",
"Rotunda",
"Sally",
"Saturday",
"Sham",
"Silverfish",
"Simpatico",
"Smiths",
"Soul",
"Spiral",
"Spring",
"Stabwounds",
"Strumbar",
"Sunday",
"Surprise",
"Survivors",
"Sushi",
"Syrup",
"Taxonomy",
"Teutonics",
"the Crustacean",
"the Loaf Dogs",
"Theatrics",
"Therapy",
"Thorns",
"Thursday",
"Tipper",
"Tongue",
"Towel",
"Train",
"Tuesday",
"Undulates",
"Variant",
"Vees",
"Vicars",
"Visage",
"Warbear",
"Wednesday",
"Weekends",
"Weelie",
"Whiplash",
"With Thugs",
"Yaks"};
	}

	else
	{
		cerr << "Error: '" << nothing << "' is not a valid internal list." << endl;
		return 1;
	}

	if(dump)
	{
		ofstream outf;
		outf.open(nothing.c_str());
		if (outf.is_open())
		{
			for(int i=0;i<st.word.size();i++)
			{
				outf << st.word[i] << '\n';
			}
			outf.close();
		}
		else{
			outf.close();
			cerr << "Error: Could not open file '" << nothing << "' for writing" << endl;
			return 1;
		}
	}

	return 0;
}

int structurise(string filename, wordlist &st)
{
	if(bstat)
		return stat(filename,st);

	ifstream datfile;
	string templine;

	// start reading datafiles into variables
	datfile.open(filename.c_str());
	if(!datfile.is_open())
	{
		cerr << "Error: " << filename << " could not be opened for read.";
		if(!nstat){
			cerr << " Using built-in list..." << endl;
			return stat(filename,st);
		}
		else{
			cerr << " Try using '-s'." << endl;
			return 2;
		}
	}
	while (!datfile.eof())
	{
		getline(datfile,templine);
		// allow comments in the data files
		if(templine[0]!='/' && templine[0]!='\n' && templine[0]!='#' && templine[0]!=';')
		{
			st.word.push_back(templine);
		}
	}
	datfile.close();

	return 0;
}

int main (int argc, char *argv[])
{
	wordlist one;
	wordlist two;

#ifdef WIN32
	bool pauseAtEnd = true;	//most Windows users don't run from terminal, so pause at end.
#else
	bool pauseAtEnd = false;
#endif

	/* parse arguments.
	 *  I threw this together really fast. I realize now that it isn't as
	 *  flexible as i'd like, but it seems to get the job done for all
	 *  reasonable situations. Maybe I'll fix it, or maybe I'll just make my
	 *  parsing functions better in the future.
	 */
	if(argc>1){
		if(strcmp(argv[1] , "-h")==0 || strcmp(argv[1] , "--help")==0 || strcmp(argv[1] , "/?")==0)
		{
			cout 
			<< "Rock Band name generator\n"
			<< "Usage: bn [OPTION]\n"
			<< "Output a random band name.\n\n"
			#ifdef default_static
			<< "  -s, --static     force built-in lists (default)\n"
			<< "  -n, --nstatic    default to data files\n"
			#else
			<< "  -s, --static     force built-in lists\n"
			<< "  -n, --nstatic    default to data files (default)\n"
			#endif
			<< "  -m, --nostatic   disable built-in lists\n"
			#ifdef WIN32
			<< "  -p               pause after display (default)\n"
			<< "  -np              disable pause on windows\n"
			#else
			<< "  -p               pause after display\n"
			#endif
			<< "      --dump       dump built-in lists to data files\n"
			<< "  -h, --help, /?   display this help and exit\n"
			<< "\nThe words for these lists were found on the internet somewhere.\n"
			<< "I cannot guarantee their accuracy.\n\n"
			<< "Source available at http://github.com/masonh/bandnames"
			<< endl;
			return 0;
		}
		else if(strcmp(argv[1] , "--dump")==0)
		{
			dump=true;
			stat(LIST1,one);
			stat(LIST2,two);
			return 0;
		}
		else if(strcmp(argv[1] , "--static")==0 || strcmp(argv[1] , "-s")==0)
		{
			bstat=true;
		}
		else if(strcmp(argv[1] , "--nstatic")==0 || strcmp(argv[1] , "-n")==0)
		{
			bstat=false;
		}
		else if(strcmp(argv[1] , "--nostatic")==0 || strcmp(argv[1] , "-m")==0)
		{
			nstat=true;
			bstat=false;
		}
		else if(strcmp(argv[1],"-p")==0)
			pauseAtEnd = true;
		else if(strcmp(argv[1],"-np")==0)
			pauseAtEnd = false;
		else{
			cout << "Unrecognised argument: '" << argv[1] << "'\n";
			cout << "Try 'bofh -h' for a list of valid arguments" << endl;
			return 0;
		}
	}

	if(structurise(LIST1,one)==2){
		cerr << "Fatal Error. Exiting..." << endl;
		return 1;
	}
	if(structurise(LIST2,two)==2){
		cerr << "Fatal Error. Exiting..." << endl;
		return 1;
	}


	srand(time(NULL));

	cout << one.word[rand()%one.word.size()]
		<< " " << two.word[rand()%two.word.size()] << endl;
	

	if(pauseAtEnd)
	{
		cout << "\nPress any key to continue..." << endl;
#ifdef _INC_CONIO
		_getch();
#else
		cin.get();
#endif
	}
	

	return 0;
}

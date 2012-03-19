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


#define FILE1 "list1.dat"
#define FILE2 "list2.dat"


class wordlist
{
	private:
	vector<string> list1;
	vector<string> list2;
		
	
	public:
	wordlist()
	{
		list1 = {
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
		list2 = {
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
	~wordlist(){}

	int load(bool verbose=false, bool nstat=false)
	{	
		int val = 0;
		val = load(FILE1 ,list1, verbose, nstat);
		val = val | load(FILE2, list2, verbose, nstat);
		return val;
	}
	
	int load(string filename, vector<string> &list, bool verbose=false, bool nstat=false)
	{
		int val = 0;
		ifstream datfile;
		datfile.open(filename.c_str());
		if(!datfile.is_open())
		{
			if(verbose || nstat)
				cerr << "Error: " << filename << " could not be opened for read.";
			if(!nstat)
			{
				if(verbose)
					cerr << " Using built-in list..." << endl;
				val = 1;
			}
			else
			{
				cerr << " Try using '-s'." << endl;
				return 2;
			}
		}
		string templine;
		while (!datfile.eof())
		{
			getline(datfile,templine);
			// allow comments in the data files
			if(templine[0]!='/' && templine[0]!='\n' && templine[0]!='#' && templine[0]!=';')
			{
				list.push_back(templine);
			}
		}
		datfile.close();
		return val;
	}
	
	bool dump()
	{
		bool val = true;
		val = dump(list1, FILE1) && dump(list2, FILE2);
	}
	bool dump(vector<string> &list, string filename)
	{
		ofstream outf;
		outf.open(filename);
		if (outf.is_open())
		{
			for(int i=0;i<list.size();i++)
			{
				outf << list[i] << '\n';
			}
			outf.close();
		}
		else{
			outf.close();
			cerr << "Error: Could not open file '" << filename << "' for writing" << endl;
			return false;
		}
		return true;
	}
	
	string random()
	{
		return random(1) + " " + random(2);
	}
	string random(int list)
	{
		srand(time(NULL));
		int pos;
		if (list==1)
		{
			pos = rand() % list1.size();
			return list1[pos];
		}
		if (list==2)
		{
			pos = rand() % list2.size();
			return list2[pos];
		}
		cerr << "Error: list " << list << " does not exist!";
		return "";
	}
	
};


int main (int argc, char *argv[])
{
	bool dump=false;	// dump internal lists to data files
	bool bstat=false;	// enable data files by default
	bool nstat=false;	// disable internal lists? default (false) enable them
	bool verbose=false;	// don't output non-fatal errors

	wordlist word;

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
	for(int i=1; i < argc; i++)
	{
		if(strcmp(argv[i] , "-h")==0 || strcmp(argv[i] , "--help")==0 || strcmp(argv[i] , "/?")==0)
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
			<< "  -v               display non-fatal errors\n"
			<< "      --dump       dump built-in lists to data files\n"
			<< "  -h, --help, /?   display this help and exit\n"
			<< "\nThe words for these lists were found on the internet somewhere.\n"
			<< "I cannot guarantee their accuracy.\n\n"
			<< "Source available at http://github.com/masonh/bandnames"
			<< endl;
			return 0;
		}
		else if(strcmp(argv[i] , "--dump")==0)
		{
			word.dump();
			return 0;
		}
		else if(strcmp(argv[i] , "--static")==0 || strcmp(argv[i] , "-s")==0)
		{
			bstat=true;
		}
		else if(strcmp(argv[i] , "--nstatic")==0 || strcmp(argv[i] , "-n")==0)
		{
			bstat=false;
		}
		else if(strcmp(argv[i] , "--nostatic")==0 || strcmp(argv[i] , "-m")==0)
		{
			nstat=true;
			bstat=false;
		}
		else if(strcmp(argv[i],"-p")==0)
			pauseAtEnd = true;
		else if(strcmp(argv[i],"-np")==0)
			pauseAtEnd = false;
		else if(strcmp(argv[i],"-v")==0)
			verbose=true;
		else{
			cout << "Unrecognised argument: '" << argv[i] << "'\n";
			cout << "Try '"<<argv[0]<<" -h' for a list of valid arguments" << endl;
			return 0;
		}
	}

	if(!bstat)
		if(word.load()>1){
			cerr << "Fatal Error. Exiting..." << endl;
			return 1;
		}



	cout << word.random() << endl;
	

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

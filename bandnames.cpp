/* 
 * outputs a random band name based on lists from Rock Band
 * I found the lists online somewhere. don't expect them to be completely accurate
 * i based my code on a previous program i wrote, bofh
 * for more info, suggestions, anything, email me at masonph@gmail.com
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
  */




//#define default_static		// disables data files by default

//#include <time.h>
//#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <initializer_list>
#include <string>
#include <string.h>
using namespace std;

bool dump=false;	// dump internal lists to data files

#ifdef default_static
bool bstat=true;	// disable data files by default. this basically converts the preprocessor defines into C variables
#else
bool bstat=false;	// enable data files by default. this basically converts the preprocessor defines into C variables
#endif
bool nstat=false;	// disable internal lists? default (false) enable them



struct wordlist
{
	int pos;
	vector<string> word;
};

int stat(string nothing, wordlist &st)
{
	cerr << "begin stat(" << nothing << "," << &st << ")" <<endl;
	string datas;
	unsigned int i;
	cerr << "about to enter data" <<endl;
	if(nothing == "list1.dat") // list 1
	{
		vector<string> datas= {
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
"Chekhovs",
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
"Galileos",
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
"Kafkas",
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
	else if(nothing == "list2.dat") // list 2
	{
		vector<string> datas={
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
		cerr << "dumping internal lists... " << endl;
		ofstream outf;
		outf.open(nothing.c_str());
		if (outf.is_open())
		{
			for(i=0;i<(sizeof(datas)/sizeof(char *));i++)
			{
				outf << datas[i] << '\n';
			}
		}
		else{
			outf.close();
			cerr << "Error: Could not open file '" << nothing << "' for writing" << endl;
			return 1;
		}
		outf.close();
		return 0;
	}
	
	cerr << "size of datas:" << sizeof(datas) << endl << "number elements:"
		<< sizeof(datas)/sizeof(char *) << endl;
	for (i=0;i<(sizeof(datas)/sizeof(char *));i++)
	{
		st.word[i].push_back(datas[i]);
	}
	cerr << "list1 entered" << endl;


	return 0;
}

int structurise(string filename, wordlist &st)
{
	if(bstat)
		return stat(filename,st);

	ifstream datfile;
	datfile.open(filename.c_str());
	string templine;
	st.pos=0;

	// start reading datafiles into variables
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
		//fscanf(datfile,"%63[^\n]\n",templine)
		getline(datfile,templine);
		if(templine[0]!='/' && templine[0]!='\n' && templine[0]!='#'){
			st.word.push_back(templine);
	   		st.pos++;
/*	   		 if (st.pos > 255)	// length of static array
	  		{
	   		 	cerr << "Error: " + filename + " max file length exceeded. Input truncated." + endl;
				break;
	 		}*/	// no longer necessary
		}
	}
	datfile.close();

	return 0;
}

int main (int argc, char *argv[])
{
	wordlist one;
	wordlist two;
	one.pos=0;
	two.pos=0;

	/* parse arguments.
	 *  I threw this together really fast. I realize now that it isn't as
	 *  flexible as i'd like, but it seems to get the job done for all
	 *  reasonable situations. Maybe I'll fix it, or maybe I'll just make my
	 *  parsing functions better in the future.
	 */ 
	//cerr << argc << " " << argv[1] << endl;
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
			<< "      --dump       dump built-in lists to data files\n"
			<< "  -h, --help, /?   display this help and exit\n"
			<< "\nThe words for these lists were found on the internet somewhere.\n"
			<< "I cannot guarantee their accuracy.\n\n"
			<< "Created by Mason Heller\n"
			<< "This program is freeware. Use and distribute as you please.\n"
			<< "For questions, comments, or full source email me at masonph@gmail.com\n";
			return 0;
		}
		else if(strcmp(argv[1] , "--dump")==0)
		{
			dump=true;
			stat("list1.dat",one);
			stat("list2.dat",two);
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
		else{
			cout << "Unrecognised argument: '" << argv[1] << "'\n";
			cout << "Try 'bofh -h' for a list of valid arguments" << endl;
			return 0;
		}
	}

	if(structurise("list1.dat",one)==2){
		cerr << "Fatal Error. Exiting..." << endl;
		return 1;
	}
	if(structurise("list2.dat",two)==2){
		cerr << "Fatal Error. Exiting..." << endl;
		return 1;
	}


	srand(time(NULL));

	cerr << "one.pos:" << one.pos << endl;
	cerr << "two.pos:" << two.pos << endl;
	int index1,index2;
	index1 = rand()%one.pos;
	index2 = rand()%two.pos;
	cerr << "rand()%one.pos:"<< index1 <<endl;
	cerr << "one.word[" << index1 << "]:" << one.word[index1] << endl;
	cout << one.word[index1];
	cout << " " << two.word[index2] << endl;
	cout << one.word[index1] << "testing" << endl;
	cout << "testing" << two.word[index2] << endl;
	cout << two.word[index2] << "testing" << endl;

	return 0;
}

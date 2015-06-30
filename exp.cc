
// LV
const int Initial_LV = 1;
const int Initial_Exp = 0;
const int Max_LV = 10;
const int LVAC_EXP[9] = {4,9,16,25,36,49,64,81,100};
const int LVUP_EXP[9] = {4,5,7 ,9 ,11,13,15,17,19};

// Initial_ABILITY
const int Initial_HP = 50;
const int Initial_HPR = 5;
const int Initial_MP = 15;
const int Initial_MPR = 5;
const int Initial_Att = 10;
const int Initial_Def = 0;

// 
const int Str_HP = 3;
const int Str_HPR = 3;
const int Int_MP = 1;
const int Int_MPR = 3;
const int Dex_Def = 1;

class EXP{
	public:
		EXP();
		void LVUP();		
		void getEXP(int exp);
	private:
		int LV;
		int UpExp;
		int AcExp;
		bool isLVUP();
};

EXP::EXP(){
	LV = Initial_LV;
 	AcExp = Initial_Exp;
	UpExp = LVUP_EXP[Initial_LV];	
}

bool EXP::isLVUP(){
	if( UpExp <= 0 ) 
		return true;
	else return false;
}

void EXP::LVUP(){
	while( LV >= Initial_LV && LV < Max_LV && isLVUP() ){
		LV += 1;
		UpExp = LVAC[LV-1] - AcExp;
		cout << "LV UP to " << LV << " !!" << endl;	
	}
}

void EXP::getEXP(int exp){
	AcExp += exp;
	UpExp -= exp;
}

class Ability{
	public:
		Ability();
		void Renew();
	private:
		int HP; 	        
		int MP; 
		int HPR;
		int MPR;
		int Att;
		int Def;
		int Str;
		int Dex;
		int Int;	
};

Ability::Ability(){
	HP = Initial_HP;	
	MP = Initial_MP;
	HPR = Initial_HPR;
	MPR = Initial_MPR;
	Attack = Initial_Att;
	Defense = Initial_Def;
}

void Ability:Renew(){
	HP += Str * Str_HP;
    HPR += Str * Str_HPR;
    MP += Int * Int_MP;
    MPR += Int * Int_MPR;
    Def += Dex_Def;	
} 

virtual class RPGPerson{	
	public:
		RPGPerson();
		void getEXP(int);
		virtual void LVUP() = 0;
	private:
		Ability ability;
		EXP exp;
};

RPGPerson::RPGPerson():Ability(),EXP(){}

void RPGPerson::getEXP(int exp){
	exp.getEXP(exp);
}

class SwordMan : public RPGPerson{
	public:
		SwordMan();
		void LVUP();
	private:
		const int SwordMan_Growth_Str = 3;
		const int SwordMan_Growth_Dex = 1;
		const int SwordMan_Growth_Int = 2;
};

SwordMan::SwordMan():RPGPerson(){
	ability.Str = 5;
	ability.Dex = 2;
	ability.Int = 3;
	ability.Renew();
	ability.Att += ability.Str;
}

void SwordMan::LVUP(){
	exp.LVUP();
	ability.Str += SwordMan_Growth_Str;
	ability.Dex += SwordMan_Growth_Dex;
	ability.Int += SwordMan_Growth_Int;
	ability.Renew();
	ability.Att += ability.Str;
}

class Assassin : public RPGPerson{
	public:
		Assassin();
		void LVUP();
	private:
		const int Assassin_Growth_Str = 2;
		const int Assassin_Growth_Dex = 3;
		const int Assassin_Growth_Int = 1;
};

Assassin::Assassin():RPGPerson(){
	ability.Str = 3;
	ability.Dex = 5;
	ability.Int = 2;
	ability.Renew();
	ability.Att += ability.Dex;
}

void Assassin::LVUP(){
	exp.LVUP();
	ability.Str += Assassin_Growth_Str;
	ability.Dex += Assassin_Growth_Dex;
	ability.Int += Assassin_Growth_Int;
	ability.Renew();
	ability.Att += ability.Dex;
}

class Magicain : public RPGPerson{
	public:
		Magicain();
		void LVUP();
	private:	
		const int Magicain_Growth_Str = 1;
		const int Magicain_Growth_Dex = 2;
		const int Magicain_Growth_Int = 3;
};

Magicain::Magicain():RPGPerson(){
	ability.Str = 2;
	ability.Dex = 3;
	ability.Int = 5;
	ability.Renew();
	ability.Att += ability.Int;
}

void Magicain::LVUP(){
	exp.LVUP();
	ability.Str += Magicain_Growth_Str;
	ability.Dex += Magicain_Growth_Dex;
	ability.Int += Magicain_Growth_Int;
	ability.Renew();
	ability.Att += ability.Int
}

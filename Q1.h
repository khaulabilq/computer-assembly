#pragma once
#include<iostream>
using namespace std;

class ALU {
private:
	int NoOfadders;
	int NoOfSubtractor;
	int NoOfRegisters;
	int sizeOfRegisters;

public:
	ALU() {
		NoOfadders = 8;
		NoOfSubtractor = 4;
		NoOfRegisters = 16;
		sizeOfRegisters = 64;

	}
	ALU(int x , int y , int z , int w) {
		NoOfadders = x;
		NoOfSubtractor = y;
		NoOfRegisters = z;
		sizeOfRegisters = w;

	}

	// getters

	int getNoOfAdders() const {
		return NoOfadders;
	}

	int getNoOfSubtractors() const { 
		return NoOfSubtractor; 
	}
	int getNoOfRegisters() const { 
		return NoOfRegisters; 
	}
	int getSizeOfRegisters() const { 
		return sizeOfRegisters; 
	}

	// setters
	void setNoOfAdders(int adders) { 
		NoOfadders = adders; 
	}
	void setNoOfSubtractors(int subtractors) { 
		NoOfSubtractor = subtractors; 
	}
	void setNoOfRegisters(int registers) {
		NoOfRegisters = registers; 
	}
	void setSizeOfRegisters(int size) {
		sizeOfRegisters = size; 
	}

	// display
	void display() const {
		cout << "ALU Specifications:" << endl;
		cout << "Number of Adders: " << getNoOfAdders() << endl;
		cout << "Number of Subtractors: " << getNoOfSubtractors() << endl;
		cout << "Number of Registers: " << getNoOfRegisters() << endl;
		cout << "Size of Registers: " << getSizeOfRegisters() << " bits" << endl;
	}
};

class ControlUnit {
private:
	float clock;
public:
	ControlUnit() {
		clock = 3;
	}
	ControlUnit(float c) {
		clock = c;
	}
	// getter
	float getClock() const {
		return clock;
	}
	// setter
	void setClock(float c) {
		clock = c;
	}

	// Display function
	void display() const {
		cout << "Control Unit Specifications:" << endl;
		cout << "Clock Speed: " << getClock() << " GHz" << endl;
	}

};

class CPU { // composition 
private:
	ALU alu;
	ControlUnit cu;
public:
	CPU() {
		alu.setNoOfAdders(8);
		alu.setNoOfSubtractors(4);
		alu.setNoOfRegisters(16);
		alu.setSizeOfRegisters(64);

		cu.setClock(3);
	}

	CPU(ALU& a , ControlUnit& c ): alu(a) , cu(c) {

	}

	// Display function
	void display() const {
		alu.display();
		cout << endl;
		cu.display();
	}

};

class MainMemory {
private:
	int capacity;
	string technologyType;
public:
	MainMemory() {
		capacity = 0; 
		technologyType = "";
	}

	MainMemory(int c, string t) {
		capacity = c; 
		technologyType = t;
	}

	// getters 
	int getCapacity() const {
		return capacity;
	}

	string getTechnologyType() const {
		return technologyType;
	}

	// setters 
	void setCapacity(int c) {
		capacity = c;
	}

	void setTechnologyType(string t) {
		technologyType = t;
	}

	void display() const {
		cout << "Main Memory Specifications:\n";
		cout << "Capacity: " << capacity << " GB\n";
		cout << "Technology Type: " << technologyType << endl;
	}

};

class Port {
	string type;
	int baud_rate;

public:
	Port(){
		type = "";
		baud_rate = 0 ;
	}
	Port(string t , int b){
		type = t ;
		baud_rate = b ;
	}

	// getters 
	string getType(){
		return type ;
	}

	int getRate(){
		return baud_rate;
	}

	// setters
	void setType(string t){
		type = t ;
	}

	void setRate(int r){
		baud_rate = r;
	}

	// Display function
	void display() const {
		cout << "Port Specifications:\n";
		cout << "Type: " << type << endl;
		cout << "Baud Rate: " << baud_rate << " Mbps\n";
	}


};

class MotherBoard {
	Port *ports; // composition
	MainMemory *mm; // aggregation
	int no;

public:

	MotherBoard(MainMemory* mem = NULL, Port*p=NULL , int num = 6 ) : mm(mem) , no(num){
		ports = new Port[no];
		for (int i = 0; i < num; i++) {
			ports[i] = p[i];
		}

	}
	~MotherBoard() {
		delete[] ports;
	}

	// Getter for ports
	Port* getPorts() const {
		return ports;
	}

	// Setter for ports
	void setPorts(Port* p) {
		ports = p;
	}

	// Getter for MainMemory
	MainMemory* getMainMemory() const {
		return mm;
	}

	// Setter for MainMemory
	void setMainMemory(MainMemory* mem) {
		mm = mem;
	}

	// Getter for number of ports
	int getNumberOfPorts() const {
		return no;
	}

	// Setter for number of ports
	void setNumberOfPorts(int num) {
		no = num;
	}

	void display() const {
		cout << "Motherboard Specifications:\n";
		cout << "Main Memory:\n";
		mm->display();
		cout << "Number of Ports: " << no << endl;
		cout << "Ports:\n";
		for (int i = 0; i < no; ++i) {
			cout << "Port " << i + 1 << ":\n";
			ports[i].display();
		}
	}
};

class PhysicalMemory {
	int capacity;
public:
	PhysicalMemory(int cap = 8) : capacity(cap) {
	}
	int getCapacity() const { 
		return capacity; 
	}
	void setCapacity(int cap) { 
		capacity = cap; 
	}

	void display() const {
		cout << "Physical Memory Specifications:\n";
		cout << "Capacity: " << capacity << " GB\n";
	}
};


class GraphicsCard {
private:
	string brand;
	int memorySize;
	double price;

public:
	// Constructors
	GraphicsCard(const string& b = "", int size = 0, double p = 0.0) : brand(b), memorySize(size), price(p) {}

	// Getters and Setters
	const string& getBrand() const { 
		return brand; 
	}
	void setBrand(const string& b) { 
		brand = b; 
	}

	int getMemorySize() const { 
		return memorySize; 
	}
	void setMemorySize(int size) { 
		memorySize = size; 
	}

	double getPrice() const { 
		return price; 
	}
	void setPrice(double p) { 
		price = p; 
	}
	// Display function
	void display() const {
		cout << "Graphics Card Specifications:\n";
		cout << "Brand: " << brand << endl;
		cout << "Memory Size: " << memorySize << " GB\n";
		cout << "Price: $" << price << endl;
	}


};

class StorageDevice {
private:
	string type;
	int capacity;
	double price;

public:
	// Constructors
	StorageDevice(const string& t = "", int cap = 0, double p = 0.0) : type(t), capacity(cap), price(p) {}

	// Getters and Setters
	const string& getType() const { 
		return type; 
	}
	void setType(const string& t) { 
		type = t; 
	}

	int getCapacity() const { 
		return capacity; 
	}
	void setCapacity(int cap) { 
		capacity = cap; 
	}

	double getPrice() const { 
		return price; 
	}
	void setPrice(double p) { 
		price = p; 
	}

	// Display function
	void display() const {
		cout << "Storage Device Specifications:\n";
		cout << "Type: " << type << endl;
		cout << "Capacity: " << capacity << " GB\n";
		cout << "Price: $" << price << endl;
	}

};


class NetworkCard {
private:
	string type;
	int speed;
	double price;

public:
	// Constructors
	NetworkCard(const string& t = "", int s = 0, double p = 0.0) : type(t), speed(s), price(p) {}

	// Getters and Setters
	const string& getType() const { 
		return type; 
	}
	void setType(const string& t) { 
		type = t; 
	}

	int getSpeed() const { 
		return speed; 
	}
	void setSpeed(int s) { 
		speed = s; 
	}

	double getPrice() const { 
		return price; 
	}
	void setPrice(double p) { 
		price = p; 
	}

	// Display function
	void display() const {
		cout << "Network Card Specifications:\n";
		cout << "Type: " << type << endl;
		cout << "Speed: " << speed << " Mbps\n";
		cout << "Price: $" << price << endl;
	}
};

class PowerSupply {
private:
	int wattage;
	string efficiencyRating;
	double price;

public:
	// Constructors
	PowerSupply(int w = 0, const string& rating = "", double p = 0.0) : wattage(w), efficiencyRating(rating), price(p) {}

	// Getters and Setters
	int getWattage() const { 
		return wattage; 
	}
	void setWattage(int w) { 
		wattage = w; 
	}

	const string& getEfficiencyRating() const { 
		return efficiencyRating; 
	}
	void setEfficiencyRating(const string& rating) { 
		efficiencyRating = rating; 
	}

	double getPrice() const { 
		return price; 
	}
	void setPrice(double p) {
		price = p; 
	}

	// Display function
	void display() const {
		cout << "Power Supply Specifications:\n";
		cout << "Wattage: " << wattage << " W\n";
		cout << "Efficiency Rating: " << efficiencyRating << endl;
		cout << "Price: $" << price << endl;
	}

};

class Battery {
private:
	int capacity;

public:
	// Constructors
	Battery(int cap = 0) : capacity(cap) {
	}

	// Getters and Setters
	int getCapacity() const { 
		return capacity; 
	}
	void setCapacity(int cap) { 
		capacity = cap; 
	}

	// Display function
		void display() const {
		cout << "Battery Specifications:\n";
		cout << "Capacity: " << capacity << " mAh\n";
	}

};

// Case Class
class Case {
private:
	string formFactor;
	string color;
	double price;

public:
	// Constructors
	Case(const string& form = "", const string& col = "", double p = 0.0) : formFactor(form), color(col), price(p) {}

	// Getters and Setters
	const string& getFormFactor() const { 
		return formFactor; 
	}
	void setFormFactor(const string& form) { 
		formFactor = form; 
	}

	const string& getColor() const { 
		return color; 
	}
	void setColor(const string& col) { 
		color = col; 
	}

	double getPrice() const { 
		return price; 
	}
	void setPrice(double p) { 
		price = p; 
	}

	void display() const {
		cout << "Case Specifications:\n";
		cout << "Form Factor: " << formFactor << endl;
		cout << "Color: " << color << endl;
		cout << "Price: $" << price << endl;
	}
};


class Computer {
	PhysicalMemory* pm;
	MotherBoard* mb;
	CPU* cpu;
	GraphicsCard* gc;
	StorageDevice* sd;
	NetworkCard* nc;
	PowerSupply* ps;
	Battery* b;
	Case* cs;
public:
	Computer(PhysicalMemory* mem = nullptr, MotherBoard* board = nullptr, CPU* processor = nullptr, GraphicsCard* gpu = nullptr, StorageDevice* storage = nullptr, NetworkCard* network = nullptr, PowerSupply* supply = nullptr, Battery* battery = nullptr, Case* pcCase = nullptr)
		: pm(mem), mb(board), cpu(processor), gc(gpu), sd(storage), nc(network), ps(supply), b(battery), cs(pcCase) {
	}


	PhysicalMemory& getPhysicalMemory() const {
		return *pm;
	}
	void setPhysicalMemory(PhysicalMemory* mem) {
		pm = mem;
	}

	MotherBoard& getMotherBoard() const {
		return *mb;
	}
	void setMotherBoard(MotherBoard* board) {
		mb = board;
	}

	CPU& getCPU() const {
		return *cpu;
	}
	void setCPU(CPU* processor) {
		cpu = processor;
	}

	void display() const {
		cout << "Computer Specifications:\n";
		pm->display();
		mb->display();
		cpu->display();
		if (gc != nullptr) gc->display();
		if (sd != nullptr) sd->display();
		if (nc != nullptr) nc->display();
		if (ps != nullptr) ps->display();
		if (b != nullptr) b->display();
		if (cs != nullptr) cs->display();
	}
};

class ComputerAssembly {
	double totalPrice;
	Computer* c;

public: 
	ComputerAssembly(): totalPrice(0), c(NULL) {

	}
	friend istream& operator>> (istream& in, ComputerAssembly& comp);
	void display() const {
		cout << "Computer Assembly:\n";
		cout << "Total Price: $" << totalPrice << endl;
		if (c != nullptr) {
			cout << "Computer Specifications:\n";
			c->display();
		}
		else {
			cout << "No computer assembled yet.\n";
		}
	}
};

class PC : public ComputerAssembly {
public:
	PC(){

	}

};

class MAC : public ComputerAssembly {
	
public:
	MAC() {

	}
};

istream& operator>> (istream& in, ComputerAssembly& comp) {

	cout << "ALU SPECIFICATIONS:\n";
	cout << "Enter no of adders: ";
	int a; 
	in >> a;
	cout << "Enter no of Subtractors: ";
	int s;
	in >> s;
	cout << "Enter no of registers: ";
	int reg;
	in >> reg;
	cout << "Enter size of registers: ";
	int size;
	in >> size;
	ALU alu(a, s, reg, size);

	cout << "CU SPECIFICATIONS: \n";
	float clock;
	while (true) {
		cout << "Enter clock speed (GHz): ";
		in >> clock;
		if (clock >= 0 && clock <= 5)
			break;
		else
			cout << "INVALID!\n";
	}
	ControlUnit cu(clock);

	CPU *cpu = new CPU (alu, cu);
	
	cout << "MAIN MEMORY SPECIFICATION: \n";
	int cap;
	while (true) {
		cout << "Enter capacity (GB): ";
		in >> cap;
		if (cap >= 4 && cap <= 512) {
			break;
		}
	}
	string tech;
	cout << "Enter technology type: ";
	in >> tech;
	MainMemory* mm = new MainMemory(cap, tech);

	cout << "PORTS SPECIFICATION: \n";
	cout << "Enter Number of Ports: ";
	int num;
	cin >> num;
	Port*p = new Port[num];
	string porttype; 
	int baudrate;
	for (int i = 0; i < num; i++) {
		cout << "Enter Type: ";
		in >> porttype;
		cout << "Enter baud rate: "; 
		in >> baudrate;
		p[i] = Port(porttype, baudrate);
	}

	MotherBoard* motherboard = new MotherBoard(mm, p, num);

	cout << "Enter Physical Memory capacity: ";
	int pc;
	cin >> pc;
	PhysicalMemory* pm = new PhysicalMemory(pc);

	cout << "GRAPHICS CARD SPECIFICATIONS:\n";
	string brand;
	int memorySize;
	double price;

	cout << "Enter brand: ";
	in >> brand;

	cout << "Enter memory size (GB): ";
	in >> memorySize;

	cout << "Enter price: ";
	in >> price;

	GraphicsCard* gc = new GraphicsCard(brand, memorySize, price);


	cout << "BATTERY SPECIFICATIONS:\n";
	int capacity;
	cout << "Enter capacity (mAh): ";
	in >> capacity;
	Battery* batt = new Battery(capacity);

	cout << "POWER SUPPLY SPECIFICATIONS:\n";
	int wattage;
	string efficiencyRating;
	double psPrice;
	cout << "Enter wattage: ";
	in >> wattage;
	cout << "Enter efficiency rating: ";
	in >> efficiencyRating;
	cout << "Enter price: ";
	in >> psPrice;
	PowerSupply* ps = new PowerSupply(wattage, efficiencyRating, psPrice);

	cout << "CASE SPECIFICATIONS:\n";
	string formFactor;
	string color;
	double casePrice;
	cout << "Enter form factor: ";
	in >> formFactor;
	cout << "Enter color: ";
	in >> color;
	cout << "Enter price: ";
	in >> casePrice;
	Case* pcCase = new Case(formFactor, color, casePrice);

	cout << "STORAGE DEVICE SPECIFICATIONS:\n";
	string type;
	capacity;
	double storagePrice;
	cout << "Enter type (e.g., HDD, SSD): ";
	in >> type;
	cout << "Enter capacity (GB): ";
	in >> capacity;
	cout << "Enter price: ";
	in >> storagePrice;
	StorageDevice* storage = new StorageDevice(type, capacity, storagePrice);

	cout << "NETWORK CARD SPECIFICATIONS:\n";
	string networkType;
	int speed;
	double networkPrice;
	cout << "Enter type (e.g., Ethernet, Wi-Fi): ";
	in >> networkType;
	cout << "Enter speed (Mbps): ";
	in >> speed;
	cout << "Enter price: ";
	in >> networkPrice;
	NetworkCard* network = new NetworkCard(networkType, speed, networkPrice);

	comp.c = new Computer(pm, motherboard, cpu, gc, storage, network, ps,batt, pcCase);
	return in;
}
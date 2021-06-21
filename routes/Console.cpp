#include "../vendor/commander/Commander.cpp"
#include "../app/types/StudentSelectionType.cpp"
#include "../app/controllers/StudentSelection.cpp"
#include "../app/controllers/RegistrationQueue.cpp"
#include "../app/controllers/SouvenirStack.cpp"

class Console
{
    private:
        bool running;
        bool regTime;
        string input;
        int quota;
        int summ;

        RegistrantQueueType registrants;
        StudentSelectionChainType candidates;
        SouvenirStackType souvenirs;

        string getInstruction() {
            cout << "> ";
            cin >> this->input;
            return this->input;
        }

        void overtimeMessage() {
            cout << "Waktu pendaftaran telah ditutup." << endl << endl;
        }

        void preCloseMessage() {
            cout << "Waktu pendaftaran belum ditutup." << endl << endl;
        }

        void routes() {
            string instruction = this->input;
            string registrantTemp;

            if (instruction.compare("daftar") == 0 && this->regTime)
                this->registrants = RegistrationQueue::from(this->registrants).add();

            else if (instruction.compare("buka") == 0 && !this->regTime) {
                cout << "Masukkan data maksimal : ";
                cin >> this->quota;
                cout << endl << endl;
                this->regTime = true;
            }

            else if (instruction.compare("daftar") == 0 && !this->regTime)
                this->overtimeMessage();
            
            else if (instruction.compare("panggil") == 0 && this->regTime) {
                if (this->summ >= this->quota) {
                    cout 
                        << "Pendaftar melebihi kuota yang ditentukan."
                        << endl << endl; 
                } else {
                    registrantTemp = RegistrationQueue::from(this->registrants).getRearTestId();
                    this->registrants = RegistrationQueue::from(this->registrants).call();
                    if (registrantTemp.compare("0") != 0) {
                        this->candidates = StudentSelection::from(this->candidates)
                            .add(registrantTemp);
                        this->souvenirs = SouvenirStack::from(this->souvenirs).pop();
                        this->summ += 1;
                    }
                }
            }

            else if (instruction.compare("panggil") == 0 && !this->regTime)
                this->overtimeMessage();

            else if (instruction.compare("seragam.status") == 0)
                SouvenirStack::from(this->souvenirs).count();

            else if (instruction.compare("seragam.tambah") == 0) 
                this->souvenirs = SouvenirStack::from(this->souvenirs).add();

            else if (instruction.compare(".exit") == 0) 
                this->running = false;

            else 
                cout << "Perintah tak ditemukan!" << endl << endl;
        }

        void run() {
            while (this->running) {
                this->getInstruction();
                this->routes();
            }
        }

    public:
        Console() {
            this->running = true;
            this->regTime = false;
            this->summ = 0;
            this->souvenirs.count = 0;
            this->souvenirs.top = NULL;
            this->registrants.count = 0;
            this->registrants.front = NULL;
            this->registrants.rear = NULL;
            this->run();
        }

        ~Console() {}
};

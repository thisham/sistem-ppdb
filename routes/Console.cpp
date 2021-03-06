#include "../vendor/commander/Commander.cpp"
#include "../app/types/StudentSelectionType.cpp"
#include "../app/controllers/RegistrationQueue.cpp"
#include "../app/controllers/StudentSelection.cpp"
#include "../app/controllers/EliminateCandidate.cpp"

class Console
{
    private:
        bool running;
        bool regTime;
        string input;

        RegistrantQueueType registrants;
        StudentSelectionChainType candidates;

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

            else if (instruction.compare("daftar") == 0 && !this->regTime)
                this->overtimeMessage();
            
            else if (instruction.compare("panggil") == 0 && this->regTime) {
                registrantTemp = RegistrationQueue::from(this->registrants).getRearTestId();
                this->registrants = RegistrationQueue::from(this->registrants).call();
                if (registrantTemp.compare("0") != 0)
                    this->candidates = *StudentSelection::from(&this->candidates).add(registrantTemp);
            }

            else if (instruction.compare("panggil") == 0 && !this->regTime)
                this->overtimeMessage();

            else if (instruction.compare("tutup") == 0 && this->regTime) 
                this->regTime = false;

            else if (instruction.compare("tutup") == 0 && !this->regTime)
                this->overtimeMessage();

            else if (instruction.compare("eliminasi") == 0 && this->regTime)
                this->preCloseMessage();

            else if (instruction.compare("eliminasi") == 0 && !this->regTime) 
                this->candidates = *EliminateCandidate::from(&this->candidates).eliminate();

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
            this->regTime = true;
            this->registrants.count = 0;
            this->registrants.front = NULL;
            this->registrants.rear = NULL;
            this->run();
        }

        ~Console() {}
};

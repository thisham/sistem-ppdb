#include "../vendor/commander/Commander.cpp"
#include "../app/controllers/Example.cpp"

class Console
{
    private:
        bool running;
        char input[60];

        string getInstruction() {
            cout << "> ";
            cin.getline(this->input, 60);
            return this->input;
        }

        void routes() {
            string instruction = this->input;

            Commander::get(instruction).address("yo help", Example::process);
            Commander::get(instruction).address("", Example::process);

            if (instruction.compare(".exit") == 0) this->running = false;
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
            this->run();
        }

        ~Console() {}
};

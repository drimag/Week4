#pragma once

void printHeader() {
	std::cout << "+-----------------------------------------------------------------------------------------+" << std::endl;
	std::cout << "| NVIDIA-SMI 555.85                 Driver Version: 555.85         CUDA Version: 12.5     |" << std::endl;
	std::cout << "|-----------------------------------------+------------------------+----------------------+" << std::endl;
	std::cout << "| GPU  Name                  Driver-Model | Bus-Id          Disp.A | Volatile Uncorr. ECC |" << std::endl;
	std::cout << "| Fan  Temp   Perf          Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute M. |" << std::endl;
	std::cout << "|                                         |                        |               MIG M. |" << std::endl;
	std::cout << "|=========================================+========================+======================|" << std::endl;
	std::cout << "|   0  NVIDIA GeForce GTX 1650 ...  WDDM  |   00000000:26:00.0  On |                  N/A |" << std::endl;
	std::cout << "| 35%   46C    P8              8W /  100W |    1849MiB /   4096MiB |      1%      Default |" << std::endl;
	std::cout << "|                                         |                        |                  N/A |" << std::endl;
	std::cout << "+-----------------------------------------+------------------------+----------------------+" << std::endl;
	std::cout << "                                                                                           " << std::endl;
}

void printProcessHeader() {
	std::cout << "+-----------------------------------------------------------------------------------------+" << std::endl;
	std::cout << "| Processes:                                                                              |" << std::endl;
	std::cout << "|  GPU   GI   CI        PID   Type   Process name                              GPU Memory |" << std::endl;
	std::cout << "|        ID   ID                                                               Usage      |" << std::endl;
	std::cout << "|=========================================================================================|" << std::endl;
}

void printMarqueeHeader() {
	std::cout << "*************************************" << std::endl;
	std::cout << "* Displaying a Marquee Console *" << std::endl;
	std::cout << "*************************************" << std::endl;
}
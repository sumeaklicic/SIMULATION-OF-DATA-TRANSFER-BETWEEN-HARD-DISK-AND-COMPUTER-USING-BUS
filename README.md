# SIMULATION-OF-DATA-TRANSFER-BETWEEN-HARD-DISK-AND-COMPUTER-USING-BUS
Buses play a big role in computers. Using Arduino, I will show how the bus works

In this paper, I will explain how buses work and what their role is in computer architecture. Using Arduino components, I performed a simulation that represents the transfer of data between a hard disk and a computer using a computer bus. There are many types of buses and their divisions, but now we are talking about the bus that connects peripheral devices. Several components such as diodes, resistors, sensors, etc. were used to make the simulation worthy of the real event.
We often encounter data transfer (e.g. from USB), and we are not aware that these are all buses. For this reason, it is important to know their functionalities. A computer bus is a set of physical connections (wires, lines or traces on the motherboard) that enable data transfer between different parts of the computer system, such as: Processor (CPU), Memory (RAM), Input/output devices (I/O devices). The bus is like a "highway" through which information moves between computer components.

The role of the computer bus in computers is to enable communication between different parts of the computer system. Without the bus, components such as the processor, memory, and devices would not be able to exchange information.
The main roles of the computer bus:
It enables data transfer between CPU, RAM and input/output devices.
For example when the CPU wants to read data from memory, the bus allows it to get to that data.
The CPU uses the address bus to say precisely which memory location it wants to read from or to which it wants to write data.
Transmission of control signals: Commands such as: "read", "write", "wait", "interrupt" are sent through the control bus. It enables synchronization and control between components. The bus enables all parts of the system to "work together", following common time signals (clock signal).
Enabling system expandability: Enables additional devices to be connected to the system (such as a keyboard, printer, disk, graphic card...).
Buses are also connected to external ports - sockets on the back of the computer case. Some of the pvih ports, such as those for the keyboard and mouse, are directly connected to the motherboard. Others, like the monitor port, are generally connected to an expansion card (video or sound, for example). Slots and ports facilitate and enable simple connection of external devices - peripheral units or peripherals.

Data transfer between a hard disk and a computer means the process in which information (files, programs, images, etc.) is moved from the disk to the memory (RAM), or vice versa — when the computer writes something to the disk.
This process takes place with the help of several key components within the computer system:
1. processor (CPU)
2. working memory (RAM)
3. disk controller
4. bus
5. hard disk
When the user initiates an action, such as opening a document or running a program, the CPU initiates a request to read data. The CPU uses the address bus to send information about where the requested data is located on the disk. This request goes to the disk controller that manages the operation of the disk. If it is a mechanical hard disk drive (HDD), the controller moves the read head to the appropriate physical location on the disk platter. If an SSD is used, the controller electronically finds the required data. Once the data is located, it is transferred to RAM via the I/O bus (eg SATA or NVMe) and the data bus. RAM serves as temporary storage because it enables much faster access to data than would be possible directly from the disk. The processor then uses the data from the RAM to perform the task. In the opposite direction, when data needs to be saved, the processor first writes that data into RAM, and then instructs the disk controller to write the data permanently to the disk. The controller retrieves the data from the RAM and writes it to the appropriate location on the disk. For larger amounts of data, a special technology called Direct Memory Access (DMA) is used, which enables direct communication between RAM and disk without engaging the CPU, thus freeing the processor for other tasks and increasing the transfer speed. The speed and efficiency of the entire process depend on the type of disk (SSD or HDD), the type of bus (SATA, PCIe, USB), the speed of the RAM, as well as the support for technologies such as DMA. Without buses that enable communication between the CPU, RAM and disk, none of these parts would be able to function together, so the bus is considered a key infrastructure that enables data transfer and proper functioning of the computer system.

<img width="432" height="283" alt="image" src="https://github.com/user-attachments/assets/93e9bd36-a031-4dcd-837a-6c0ab910c7a5" />

ARDUINO PROJECT

In the following photos we can see what several components look like that simulate and display data transfer in a simple way.

<img width="644" height="441" alt="image" src="https://github.com/user-attachments/assets/f9ada38f-ad3c-449e-905a-f1970063ecd5" />

The first thing we see is a traffic light. It signals whether the bus is free or not. When the green light is on, it means that the bus is free and not processing anything. When a process approaches it at a certain distance (in my case 5cm), it turns yellow, and when it starts processing, the bus turns red. This is a sign that the process is executing and the bus is no longer free. This component helps us know whether the bus is doing something or is free. It contributes a lot to the simulation so that we know what is happening inside at what moment.
Next to the bus, we see a sensor. The picture shows one of the two sensors used in the project. They detect the distance of the process and help the bus change color because in relation to the distance they detect, this is how the bus behaves.

<img width="557" height="417" alt="image" src="https://github.com/user-attachments/assets/815b57c1-a0ba-4b58-ae97-dd73b619e238" />

There is another sensor on the other side. The reason why there are two sensors is the priority of the process. In reality, there are higher and lower priority processes, and one sensor that is placed higher (the sensor from the first photo) reads the distance of the higher priority process, while this lower placed sensor (right next to the traffic light) reads the distance of the lower priority process. The idea is that when a higher priority process approaches, the way is cleared for the execution of that process due to its degree of importance. That's why there are two sensors so that we can differentiate the priority level of each process.
We also see the buzzer (sound component) in the picture. Its role is to make a sound after the data transfer process is completed. After we hear that sound, it means that the desired action has been done.

<img width="427" height="571" alt="image" src="https://github.com/user-attachments/assets/814de61a-1be1-4895-a1ff-90887eefb41c" />

We have two colors of diodes, white and blue. The priority of the process depends on which one will be turned on. The different colors are there with the aim of knowing what degree of importance the process is taking place at that moment. They light up slightly, flicker, and after the flickering we hear the sound of a buzzer that signals the end of the execution of the action.

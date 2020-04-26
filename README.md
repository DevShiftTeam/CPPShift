# CPPShift

I thought to myself that building microservices on the same machine by uploading them as threads or processes and using thread/IPC technologies such shared memory and message passing models will be much more efficient then using network requests if our services are running on the same machine/VM/Container.

The most popular approach today is developing using web microservices which use an API such as REST or SOAP, etc. This kind of solution is greate for network distributed software that run on separate machines, and I still didn't find a system that supports both approaches under the same framework. What if I could structure my application in a way that some microservices run on the same machine and some on others, and the framework will automatically determine what is the best communication way depending on where the services are and will implement it for you while hiding the implementation details, and will also be cross-platform? That is what this project is striving to achieve.

The main idea right now, is to keep a shared configuration that will indicate the locations of all the other relevant microservices for each microservice, and build a mechanism that allows for data streaming between microservices using the same interface, while by the configurations it determines the communication method to implement and runs it for you (Atomic/mutex/locks for threads, shared memory/other IPC for processes/Network).

Another end goal, is that microservices will be able to compile as dynamic libraries and loaded using a central system that runs them as threads/processes as dictated through the configuration file. Also a a CLI for making, managing and communicating with our distributed applications. For example we will be able to create a process as an app by the CLI as `cpps --create-app <app-name>`, and then attach a dynamic library or executables as microservices that define the app as `cpps --attach-[lib|exec] <path> <app-name>`, and other useful stuff as editing/updating configurations and nodes, tracking the state of our application, and more.

Well for now it is only an idea for fun and experiments, hope it will grow and help me and other. Your help, guidance and ideas are more then welcome! :)
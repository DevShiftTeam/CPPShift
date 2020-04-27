# CPPShift

Building microservices on the same machine by uploading them as threads or processes and using thread/IPC technologies such as shared memory and message passing, will be much more efficient then using network requests if our services are running on the same machine/VM/Container.

The most popular approach today is to use web microservices which implement an API such as REST or SOAP, etc. This kind of solution is great for network distributed software that run on separate machines, and I still didn't find a system that supports both local and network approaches under the same framework. What if you could structure your application in a way that some microservices run on the same machine and some on others, while the framework will automatically determine what is the best communication way depending on where the services are, and will implement it for you while hiding the implementation details, and will also be cross-platform. That is what this project is striving to achieve. Of course there are Message Passing Interfaces (MPI's) available that allow to pass messages between different processes, threads and network nodes while hiding the implementation details by providing a simple send-receive interface. But they do not provide the ability to start and manage processes and threads on demand/automatically using configurations - these types of mechanisms need to be built from ground for every project.

The main idea right now, is to keep a shared configuration that will indicate the locations of all the other relevant microservices for each microservice, and build a mechanism that allows for data streaming between microservices using the same interface, while by the configurations it determines the communication method to implement and runs it for you (Atomic/mutex/locks for threads, shared memory/other IPC for processes/Network). Might use an MPI implementation for this part.

Another end goal, is that microservices will be able to compile as dynamic libraries and loaded using a central system that runs them as threads/processes as dictated through the configuration file. Also a CLI for making, managing and communicating with our distributed applications. For example we will be able to start a microservice app by the CLI as `cpps --create-app <app-name>`, and then attach a dynamic library or executables as microservices that define the app with something like `cpps --attach-[lib|exec] <path> <app-name>`, and other useful stuff such as editing/updating configurations and nodes, tracking the state of our application, and more.

For that we will develop a project template that can compile both to an execetuable or library and will implement the framework and it's features to communicate with each other. And will also develop a CLI for configuring and managing your software components at run-time.

Well, for now it is only an idea for fun and experiments, hope it will grow and help me and others. Your help, guidance and ideas are more then welcome! :)

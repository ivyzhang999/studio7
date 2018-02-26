# Studio Questions / Replies

***Q1.1 There are two aspects to configuring a sketch to use a particle function:  defining a function with an appropriate signature and configuring it so it will act as a Particle function.  Explain each of these steps based on your review of the API:***

* Defining a function: we want a function to be triggered every time we make a call to the API. We design a function to be performed in such a way that it can know the current state and update variables outside its scope to change it.
* Conifiguring it: we need to call Particle.function() and provide a function name to be called when we make the API call.

***Q1.2 Discuss the meaning of each of the parameters/arguments to functions described above (there should be two functions: a user created one and one that is part of the Particle API)***

* User-created function: we pass a 'lightStatus' boolean that turns the lamp on or off.
* Particle API: Particle.function() takes two arguments: the name of the string we want when POSTing to the URL over HTTP, and the actual function we want to be triggered when that request is made.

***Q2. In your own words, explain the parameters/arguments given to `Particle.variable()`***

Particle.variables() takes 2 paramters. The first is a string which is used to construct the URL which we will subsequently make GET requests in order to determine the value of the variable. The second parameter is the actual variable (in code) whose value will be reported upon the HTTP request.

***Q3. "When accessing variables through Particle Dev or the on-line Console, polling is triggered by a person".  Explain what that previous sentence refers to (how does the person trigger the polling):***

***Q4. Many particle functions, like `Particle.function()` and `Particle.variable()`, require both a string and another parameter.  Explain how each relates to what is externally visible (accessible from the internet) vs. what is relevant internal to the sketch.  Make changes to verify your understanding as necessary***.

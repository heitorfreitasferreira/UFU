const express = require("express")
const server = express()

const middlerwareLocal = function(req,res,next){
    // processamento do nó
    console.log("Passou pelo middleware 1")
    //Chamada do proximo middleware
    next()
}
const middlerwareGlobal = function(req,res,next){
    console.log("Passou pelo middleware global")
    next()
}

// Configuração do middleware que é executado antes de todas as rotas
server.use(middlerwareGlobal)

//Rotas

//Rota que usa o middlewareLocal
server.get("/com",middlerwareLocal, function(req,res){
    res.send("Hello World")
})
// Rota que não usa o middleware1
server.get("/sem",function(req,res){
    res.send("Hello World")
})

// Execução do servidor na porta 3000
server.listen(3000,function(){
    console.log("Server is running")
})
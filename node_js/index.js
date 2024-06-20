const { execFile } = require('child_process');
const express = require('express');
const bodyParser = require('body-parser');
const http = require('http');

const urlencodedParser = bodyParser.urlencoded({ extended: false });

const app = express();
app.set('view engine', 'ejs');

app.get("/", (req, res) => {
    res.render('check');
});

const executablePath = './main.exe';

app.post('/check', urlencodedParser, (req, res) => {
    let username = req.body.username;

    execFile(executablePath, [username], (error, stdout, stderr) => {
        let responseMessage = `Пользователь ${username}`

        if (stdout == 'User not found') {
            responseMessage += ' нет'
        } else {
            responseMessage += ' имеет привилегию ' + stdout
        }

        res.render('info', {message: responseMessage})

    });
});



app.listen(3500);
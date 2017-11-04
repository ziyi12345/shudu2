function insert(){
    var express = require('express');
    var app = express();
    var mysql = require('mysql');
    app.get('/', function (req, res) {
        res.sendfile(__dirname + "/" + "insert.html");
    })

    var connection = mysql.createConnection({
        host: 'localhost',
        user: 'root',
        password: '123456',
        database: 'test',
        port: '3306'
    });
    connection.connect(function (err) {
        if (err) {
            console.log('[query] - :' + err);
            return;
        }
    })
    console.log('[connection connect]  succeed!');


        app.get('/test/txl%20(1)/txl/insert.html', function (req, res) {
            var name = req.query.name;
            var address = req.query.address;
            var phone = req.query.phone;
            var vx = req.query.vx;
            var e_mail = req.query.e_mail;
            var qq = req.query.qq;
            var inl = req.query.inl;
            connection.query('insert into student_record set ?', user, function (err, rs) {
                if (err) throw err;
                console.log('ok');
                res.sendfile(__dirname + "/" + "index.html");
            })
        })

/*
  " if (err) {

        console.log('[INSERT ERROR] - ', err.message);

        return;

    }*/

    connection.end();

    }


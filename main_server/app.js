var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var compression = require("compression");
var helmet = require("helmet");
var mongoose = require("mongoose");
var session = require("express-session");

// config 정보
const config = require("./config/index");

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var devicesRouter = require('./routes/devices')

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

app.use(compression());
app.use(helmet());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// Development용 Session
app.use(session({
	secret : config.secret,
	resave : false,
	saveUninitialized : true,
	cookie : {}
}));

// 라우터 등록
app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use("/devices", devicesRouter);

// config에 있는 DB 정보와 mongoose로 mongoDB 연결
mongoose.Promise = global.Promise;
mongoose.connect(config.db.uri, config.db.options)
.then(() => console.log("Successfully connected to mongodb"))
.catch(e => console.error(e));

// Error 처리하는 코드.
// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});
/*
	Error 처리하는 미들웨어는 항상 마지막에 위치해야한다.
	반드시 404 Error가 500 Error 처리하는 부분보다 위쪽에 자리하고 있어야한다.
 */
// ----

module.exports = app;

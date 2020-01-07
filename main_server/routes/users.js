var express = require('express');
var router = express.Router();
var UserController = require("../controllers/user");

/* GET users listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.post("/join", UserController.join);


/*
router.get("/login", function(req, res, next){
	res.status(200).send({ msg : "SUCCESS"});
})
*/





module.exports = router;

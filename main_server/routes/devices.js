var express = require('express');
var router = express.Router();
var DeviceController = require("../controllers/device");

/* GET devices listing. */
router.get('/', function(req, res, next) {
  res.send('respond with a resource');
});

router.post("/add", DeviceController.addDevice);


/*
router.get("/login", function(req, res, next){
	res.status(200).send({ msg : "SUCCESS"});
})
*/





module.exports = router;

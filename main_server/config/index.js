
const config = {
	//env = "development",
	ip : "http://localhost:",
	PORT : 3000,
	//mongoDB 계정 정보 입력
	db : {
		id : "psd_admin",
		pwd : "psdadminpwd",
		name : "psd_db"
	}
};

config.db.uri = "mongodb://" + config.db.id + ":" + config.db.pwd + "@127.0.0.1:27017/admin"

config.db.options = {
	dbName: config.db.name, 
	useNewUrlParser : true, 
	useCreateIndex : true, 
	useUnifiedTopology:true
};

module.exports = config;
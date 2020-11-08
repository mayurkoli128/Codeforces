create database AppointmentSys;
use AppointmentSys;

-- All about doctors...---

create table specialization 
(
    id INT AUTO_INCREMENT,
    specialization_name varchar(30) not null,
    unique(specialization_name),
    primary key(id)
)
create table doctor
(
	id int AUTO_INCREMENT,
    first_name varchar(30) not null,
    last_name varchar(30) not null,
    gender char(1),
    qualification varchar(50) not null,
    phone_no varchar(13),
    specialization_id int,
    email varchar(30),
    username varchar(30) not null,
    password varchar(30) not null,
    doctor_details varchar(1000) not null,
    primary key (id),
	foreign key (specialization_id) references specialization(id),
    unique(email),
    unique(phone_no)
)
create table doctor_availability 
(
	id int auto_increment,
    doctor_id int,
    day_of_week varchar(10) not null,
    start_time time not null,
    end_time time not null,
	is_available char(1) not null,
    reason_of_unavailability varchar(1000),
    primary key(id),
    foreign key(doctor_id) references doctor(id)
)

-- all about client---

create table patient_account
(
	id int auto_increment,
	first_name varchar(30) not null,
    last_name varchar(30) not null,
    gender char(1),
    age int(2) not null,
    phone_no varchar(13),
    email varchar(30),
    username varchar(30) not null,
    password varchar(30) not null,
    primary key(id),
    unique(phone_no),
    unique(email)
) 
create table patient_review
(
	id int auto_increment,
    patient_account_id int,
    doctor_id int,
    overall_ratings int not null,
    review varchar(1000) not null,
    review_date date,
    is_doctor_recommended char(3),
    primary key(id),
    foreign key(doctor_id) references doctor(id),
    foreign key(patient_account_id) references patient_account(id)
)
-- managing appointment's--

create table appointment_status 
(
	id int auto_increment,
    status varchar(30),
    primary key(id)
)
create table appointment
(
	id int auto_increment,
    patient_account_id int,
    doctor_id int,
    appointment_status int,
    appointment_date date not null,
    start_time time not null,
    end_time time not null,
    primary key(id),
	foreign key(doctor_id) references doctor(id),
    foreign key(patient_account_id) references patient_account(id)
)
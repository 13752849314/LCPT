package com.happygh0st.lcpt.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.sql.Date;
import java.sql.Timestamp;

@Data
public class User {
    private Integer id;
    private String username;
    private String password;
    private String phone;
    private String email;
    private String openId;
    private String roles;
    @JsonFormat(pattern = "yyyy-MM-dd")
    private Date birthday;
    private Timestamp createdAt;
    private Timestamp updatedAt;
    private Timestamp deletedAt;
}

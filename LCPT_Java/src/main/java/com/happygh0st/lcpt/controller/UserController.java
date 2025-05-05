package com.happygh0st.lcpt.controller;

import com.happygh0st.lcpt.entity.User;
import com.happygh0st.lcpt.mapper.UserMapper;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user")
public class UserController {
    private final UserMapper userMapper;

    public UserController(UserMapper userMapper) {
        this.userMapper = userMapper;
    }

    @GetMapping("/{id}")
    public User test(@PathVariable Integer id) {
        return userMapper.getUserById(id);
    }
}

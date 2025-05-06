package com.happygh0st.lcpt.controller;

import com.happygh0st.lcpt.commons.Results;
import com.happygh0st.lcpt.entity.User;
import com.happygh0st.lcpt.service.UserService;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user")
public class UserController {
    private final UserService userService;

    public UserController(UserService userService) {
        this.userService = userService;
    }

    @GetMapping("/{id}")
    public Results test(@PathVariable Integer id) {
        User user = userService.getUserById(id);
        return Results.success().addData("user", user);
    }
}

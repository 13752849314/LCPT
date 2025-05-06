package com.happygh0st.lcpt.service.impl;

import com.happygh0st.lcpt.entity.User;
import com.happygh0st.lcpt.mapper.UserMapper;
import com.happygh0st.lcpt.service.UserService;
import org.springframework.stereotype.Service;

@Service
public class UserServiceImpl implements UserService {

    private final UserMapper userMapper;

    public UserServiceImpl(UserMapper userMapper) {
        this.userMapper = userMapper;
    }

    @Override
    public User getUserById(Integer id) {
        return userMapper.getUserById(id);
    }
}

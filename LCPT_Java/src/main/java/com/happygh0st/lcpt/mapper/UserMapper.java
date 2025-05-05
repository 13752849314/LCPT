package com.happygh0st.lcpt.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.happygh0st.lcpt.entity.User;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper extends BaseMapper<User> {
    User getUserById(int id);
}

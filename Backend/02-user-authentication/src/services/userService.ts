import bcrypt from "bcrypt";
import type { IUserCreate } from "../interfaces/userInterface";
import { prisma } from "../prisma";
import { CustomError } from "../helpers/customError";

class UserService {
  async create(userData: IUserCreate) {
    userData.password = await bcrypt.hash(userData.password, 10);

    const userDB = await prisma.user.create({ data: userData });

    const { password, ...user } = userDB;

    return user;
  }

  async getOne(id: string) {
    const userDB = await prisma.user.findUnique({ where: { id } });

    if (!userDB) throw new CustomError("User not found", 404);

    const { password, ...user } = userDB;

    return user;
  }
}

export const userService = new UserService();

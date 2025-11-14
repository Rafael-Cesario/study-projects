import type { Request, Response } from "express";

class UserController {
  async create(_req: Request, _res: Response) {
    console.log("Hello");
  }
}

export const userController = new UserController();
